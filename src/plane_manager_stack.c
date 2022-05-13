/*
 * TAGS: struct, enum, typedef, pointer, function
 * notes: struct passed by reference
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 20
#define MAX_SEATS 200

// unnecessary = 0/1, but still useful for explanation
typedef enum { FALSE = 0, TRUE = 1 } boolean;
typedef enum { MAINTENANCE, DEPOSIT, OK } planeStatus;

typedef struct {
  int id;
  char surname[MAX_STRING_LENGTH];
  char name[MAX_STRING_LENGTH];
  boolean available;
} Seat;

typedef struct {
  char name[20];
  int current_n_seats;
  int n_seats;
  planeStatus status;
  Seat *seat_ptrs[MAX_SEATS];
} Plane;

Plane create_plane(const char *name, int n_seats);
Seat create_seat();
int add_seat_to_plane(Plane *plane, Seat *seat);
int add_n_seats_to_plane(Plane *plane, Seat *seats, size_t n_seats);
int insert_reservation(Plane *plane, int id, const char *name,
                       const char *surname);
int delete_reservation(Plane *plane, int seat_id);
int get_available_seats(const Plane *plane);
int print_passengers_list(const Plane *plane);
int print_seats_list(const Plane *plane);
char *get_plane_status(Plane *plane);

Plane create_plane(const char *name, int n_seats) {
  Plane p;
  strncpy(p.name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  p.current_n_seats = 0;
  p.n_seats = n_seats;
  p.status = MAINTENANCE;
  return p;
}

Seat create_seat() {
  Seat s;
  return s;
};

int add_seat_to_plane(Plane *plane, Seat *seat) {
  if (plane->current_n_seats == plane->n_seats)
    return 1;
  seat->available = TRUE;
  seat->id = plane->current_n_seats;
  *(plane->seat_ptrs + plane->current_n_seats) = seat;
  plane->current_n_seats++;
  printf("Adding seat at address %p to plane\n", seat);
  return 0;
}

int add_n_seats_to_plane(Plane *plane, Seat *seats, size_t n_seats) {
  int i;
  for (i = 0; i < n_seats; ++i) {
    add_seat_to_plane(plane, &(seats[i]));
  }
  return 0;
}

int get_available_seats(const Plane *plane) {
  int counter = 0;
  for (int i = 0; i < plane->current_n_seats; ++i) {
    printf("Plane seats %d available %d, counter %d\n", i,
           plane->seat_ptrs[i]->available, counter);
    if (plane->seat_ptrs[i]->available == TRUE)
      counter++;
  }
  return counter;
}

int print_passengers_list(const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seat_ptrs[i];
    if (!s->available)
      printf("Seat %d: %s %s\n", s->id, s->surname, s->name);
  }
  return 0;
}

int print_seats_list(const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seat_ptrs[i];
    printf("Seat: %d", s->id);
    if (s->available) {
      printf("; Available\n");
    } else {
      printf("; reserved by %s %s\n", s->surname, s->name);
    }
  }
  return 0;
}

int insert_reservation(Plane *plane, int id, const char *name,
                       const char *surname) {
  if (id >= plane->n_seats)
    return 1;
  Seat *seat = plane->seat_ptrs[id];
  if (!seat->available)
    return 1;
  strncpy(seat->surname, surname,
          strlen(surname) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH
                                              : strlen(surname));
  strncpy(seat->name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  seat->available = FALSE;
  printf("Inserted reservation for seat at address %p from %s %s\n", seat,
         surname, name);
  return 0;
}

int delete_reservation(Plane *plane, int seat_id) {
  printf("Deleting seat with id %d at address %p\n", seat_id,
         &(plane->seat_ptrs[seat_id]));
  if (seat_id >= plane->n_seats)
    return 1;
  if (plane->seat_ptrs[seat_id]->available)
    return 1;
  plane->seat_ptrs[seat_id]->available = TRUE;
  strncpy(plane->seat_ptrs[seat_id]->name, "", 0);
  strncpy(plane->seat_ptrs[seat_id]->surname, "", 0);
  return 0;
}

char *get_plane_status(Plane *plane) {
  switch (plane->status) {
  case MAINTENANCE:
    return "maintenance";
  case DEPOSIT:
    return "deposit";
  case OK:
    return "ok";
  default:
    return "";
  }
}

int main(int argc, char *argv[]) {
  const int n_seats = 12;
  Plane p = create_plane("Boeing", n_seats);
  printf("%s %lu\n", p.name, strlen(p.name));

  printf("Test creating %d seats\n", n_seats);
  Seat seats[MAX_SEATS];
  for (int i = 0; i < n_seats; ++i) {
    seats[i] = create_seat();
    printf("Created seat %.2d\t internal mem adrredss %p\n", i, &seats[i]);
  }
  printf("****\n");

  printf("Test adding %d seats in bulk\n", n_seats);
  // Note how we pass the address, not the whole structure
  add_n_seats_to_plane(&p, seats, n_seats);
  printf("****\n");

  int n = get_available_seats(&p);
  printf("Available seats: %d\n", n);
  printf("****\n");

  int n_reservations = 5;
  printf("Test inserting %d reservation (same name and surname)\n",
         n_reservations);
  for (int i = 0; i < n_reservations; i++) {
    int ret = insert_reservation(&p, i, "Name", "Surname");
  }
  printf("****\n");
  printf("Test inserting another reservation for already booked sea \n");
  int ret = insert_reservation(&p, 0, "Name", "Surname");
  if (ret) {
    printf("As expected, reservation could not be inserted\n");
  }
  else {
    printf("Error, reservation inserted even if already present\n");
  }
  printf("****\n");

  n = get_available_seats(&p);
  printf("Available seats: %d\n", n);
  printf("****\n");
  // Passenger list
  printf("Passengers list\n");
  print_passengers_list(&p);
  printf("****\n");
  printf("Seats list\n");
  print_seats_list(&p);
  printf("****\n");

  int n_delete_reservations = 2;
  printf("Test deleting %d reservation\n", n_delete_reservations);
  for (int i = 0; i < 2; i++) {
    int res = delete_reservation(&p, i);
    printf("Delete reservation %d, res = %d\n", i, res);
  }
  printf("****\n");

  n = get_available_seats(&p);
  printf("Available seats on plane: %d\n", n);
  printf("****\n");

  /* printf("Test print to file\n"); */
  /* print_passengers_list(&p); */
  /* for (int i = 0; i < 4; ++i) { */
  /*   free((p->seats)[i]); */
  /* } */
  /* free(p->seats); */

  return 0;
}
