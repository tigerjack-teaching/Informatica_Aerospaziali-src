/*
 * TAGS: struct, enum, typedef, pointer, function
 * notes: struct passed by reference
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 20

// unnecessary = 0/1, but still useful for explanation
typedef enum { FALSE = 0, TRUE = 1 } boolean;
typedef enum { MAINTENANCE, DEPOSIT, OK } planeStatus;

typedef struct {
  int id;
  char surname[20];
  char name[20];
  boolean available;
} Seat;

typedef struct {
  char name[20];
  int current_n_seats;
  int max_n_seats;
  Seat **seats;
  planeStatus status;
} Plane;

Plane *create_plane(const char *name, int max_n_seats);
Seat *create_seat();
int add_seat_to_plane(Plane *plane, Seat *seat);
int add_n_seats_to_plane(Plane *plane, Seat **seats, size_t n_seats);
int insert_reservation(Plane *plane, int id, const char *name,
                       const char *surname);
int delete_reservation(Plane *plane, int seat_id);
int get_available_seats(const Plane *plane);
int print_passengers_list(const Plane *plane);
int print_seats_list(const Plane *plane);
char *get_plane_status(Plane *plane);

Plane *create_plane(const char *name, int max_n_seats) {
  Plane *s = (Plane *)malloc(sizeof(Plane));
  strncpy(s->name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  s->current_n_seats = 0;
  s->max_n_seats = max_n_seats;
  s->seats = (Seat **)malloc(sizeof(Seat *) * max_n_seats);
  s->status = MAINTENANCE;
  return s;
}

Seat *create_seat() {
  Seat *s = (Seat *)malloc(sizeof(Seat));
  return s;
}

int add_seat_to_plane(Plane *plane, Seat *seat) {
  if (plane->current_n_seats == plane->max_n_seats)
    return 1;
  seat->available = TRUE;
  seat->id = plane->current_n_seats;
  *(plane->seats + plane->current_n_seats++) = seat;
  return 0;
}

int add_n_seats_to_plane(Plane *plane, Seat **seats, size_t n_seats) {
  for (int i = 0; i < n_seats; ++i) {
    add_seat_to_plane(plane, seats[i]);
  }
  return 0;
}

int get_available_seats(const Plane *plane) {
  int counter = 0;
  for (int i = 0; i < plane->current_n_seats; ++i) {
    if (plane->seats[i]->available)
      counter++;
  }
  return counter;
}

int print_passengers_list(const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seats[i];
    if (!s->available)
      printf("Seat %d: %s %s\n", s->id, s->surname, s->name);
  }
  return 0;
}

int print_seats_list(const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seats[i];
    printf("Seat: %d ", s->id);
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
  if (id >= plane->max_n_seats)
    return 1;
  Seat *seat = plane->seats[id];
  if (!seat->available)
    return 1;
  strncpy(seat->surname, surname,
          strlen(surname) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH
                                              : strlen(surname));
  strncpy(seat->name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  seat->available = FALSE;
  return 0;
}

int delete_reservation(Plane *plane, int seat_id) {
  if (seat_id >= plane->max_n_seats)
    return 1;
  Seat *s = plane->seats[seat_id];
  if (s->available)
    return 1;
  s->available = 1;
  strncpy(s->name, "", 0);
  strncpy(s->surname, "", 0);
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
  Plane *p = create_plane("Boeing", n_seats);
  printf("%s %lu\n", p->name, strlen(p->name));

  printf("Test creating %d seats\n", n_seats);
  Seat *ss[n_seats];
  for (int i = 0; i < n_seats; ++i) {
    ss[i] = create_seat();
    printf("Creating seat %.2d\t internal mem adrredss %p\n", i, ss[i]);
  }
  printf("****\n");

  printf("Test adding %d seats in bulk\n", n_seats);
  add_n_seats_to_plane(p, ss, n_seats);
  printf("****\n");

  int n = get_available_seats(p);
  printf("Available seats: %d\n", n);
  printf("****\n");

  int n_reservations = 5;
  printf("Test insert reservation (same name and surname)\n");
  for (int i = 0; i < n_reservations; i++) {
    int ret = insert_reservation(p, i, "Name", "Surname");
    if (ret) {
      printf("Error while insering reservation");
    }
  }
  printf("****\n");

  n = get_available_seats(p);
  printf("Available seats: %d\n", n);
  // Passenger list
  print_passengers_list(p);
  print_seats_list(p);
  printf("****\n");

  printf("Test delete reservation\n");
  for (int i = 0; i < 2; i++) {
    delete_reservation(p, i);
  }
  printf("****\n");

  n = get_available_seats(p);
  printf("Available seats on plane: %d\n", n);
  printf("****\n");

  printf("Test print\n");
  const char *path = "plane_list.txt";
  print_passengers_list(p);

  /* for (int i = 0; i < 4; ++i) { */
  /*   free((p->seats)[i]); */
  /* } */
  /* free(p->seats); */

  return 0;
}
