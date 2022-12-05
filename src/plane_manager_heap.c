/*
 * TAGS: struct, enum, typedef, pointer, function, malloc
 * notes: struct passed by reference
 *
 * Simulazione creazione areo con heap.
 *
 * Cerca DIFF per le differenze con la versione con stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 50
#define MAX_RESERVATION 200
#define MAX_PLANES 10

typedef enum { FALSE = 0, TRUE = 1 } boolean;
typedef enum { MAINTENANCE, DEPOSIT, OK } plane_status;
typedef enum { BOOKING, CONFIRMED, DELETED } reservation_status;

typedef struct {
  char name[MAX_STRING_LENGTH];
  int n_seats;
  int n_seats_available;
  plane_status status;
  // Array di puntatori a seat
} plane_t;

typedef struct {
  int id;
  char plane_name[MAX_STRING_LENGTH];
  int seat_id;
  char surname[MAX_STRING_LENGTH];
  char name[MAX_STRING_LENGTH];
  char status;
} reservation_t;

/* NB: Gli array globali sono sempre inizializzati a 0 */
// DIFF: Array di puntatori
plane_t* g_planes[MAX_PLANES];
int g_number_planes;
// DIFF: Array di puntatori
reservation_t* g_reservations[MAX_RESERVATION];
unsigned g_reservation_id;

plane_t *create_plane(const char *name, int n_seats);
plane_t *get_plane_by_name(const char *name);
char *get_plane_status(const plane_t *plane);
/**/
int insert_reservation(plane_t *plane, int seat_id, const char *name,
                       const char *surname);
int delete_reservation(int reservation_id);
char *get_reservation_status(const reservation_t *reservation);
reservation_t *get_reservation(char *surname, char *name);
/**/
int print_plane(const plane_t *plane);
int print_reservations_by_plane(const plane_t *plane);
int print_reservations_by_plane_name(const char *name);
int print_reservation(reservation_t *reservation);
int print_reservations();

plane_t *create_plane(const char *name, int max_n_seats) {
  plane_t *p = (plane_t *)malloc(sizeof(plane_t));
  size_t slen =
      strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name);
  strncpy(p->name, name, slen);
  p->name[slen] = '\0';
  p->n_seats_available = max_n_seats;
  p->n_seats = max_n_seats;
  p->status = MAINTENANCE;
  g_planes[g_number_planes] = p;
  g_number_planes++;
  return p;
}

char *get_plane_status(const plane_t *plane) {
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

plane_t* get_plane_by_name(const char *name) {
  for (int i = 0; i < g_number_planes; i++) {
    if (!strcmp(g_planes[i]->name, name)) {
      return g_planes[i];
    }
  }
  return NULL;
}

int insert_reservation(plane_t *plane, int seat_id, const char *name,
                       const char *surname) {
  if (seat_id >= plane->n_seats)
    /* Gli id dei seat sono numerati da 0 a n_seats-1, per cui un id piu' alto
       e' un errore */
    return 1;
  reservation_t *reservation = (reservation_t *)malloc(sizeof(reservation_t));
  reservation->id = g_reservation_id++;
  size_t slen = strlen(surname) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH - 1
                                                    : strlen(surname);
  strncpy(reservation->surname, surname, slen);
  reservation->surname[slen] = '\0';

  slen =
      strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH - 1 : strlen(name);
  strncpy(reservation->name, name, slen);
  reservation->name[slen] = '\0';

  slen = strlen(plane->name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH - 1
                                                 : strlen(plane->name);
  strncpy(reservation->plane_name, plane->name, slen);
  reservation->plane_name[slen] = '\0';

  reservation->seat_id = seat_id;
  reservation->status = CONFIRMED;
  plane->n_seats_available--;
  printf("Inserted ");
  print_reservation(reservation);
  g_reservations[reservation->id] = reservation;
  return 0;
}

int delete_reservation(int reservation_id) {
  reservation_t* reservation = g_reservations[reservation_id];
  char *plane_name = reservation->plane_name;
  plane_t* plane = get_plane_by_name(plane_name);
  // DIFF: liberiamo direttamente l'area di heap occupata dalla prenotazione
  /* reservation->status = DELETED; */
  plane->n_seats_available++;
  /* g_reservations[reservation_id] = reservation; */
  free(g_reservations[reservation_id]);
  printf("Delete reservation %d\n", reservation_id);
  return 0;
}


char *get_reservation_status(const reservation_t *reservation) {
  switch (reservation->status) {
  case CONFIRMED:
    return "confirmed";
  case BOOKING:
    return "booking";
  case DELETED:
    return "deleted";
  default:
    return "WRONG";
  }
}

reservation_t* get_reservation(char *surname, char *name) {
  for (int i = 0; i < g_reservation_id; i++) {
    if (!strcmp(g_reservations[i]->surname, surname) &&
        !(strcmp(g_reservations[i]->name, name))) {
      break;
    }
  }
  return NULL;
}

int print_plane(const plane_t *plane) {
  printf("Plane: %s, {seats: %d, seats_available: %d, status: %s}\n",
         plane->name, plane->n_seats, plane->n_seats_available,
         get_plane_status(plane));
  return 0;
}

int print_reservations_by_plane_name(const char *name) {
  for (int i = 0; i < g_reservation_id; i++) {
    reservation_t* reservation = g_reservations[i];
    if (reservation->status == CONFIRMED &&
        !strcmp(reservation->plane_name, name)) {
      print_reservation(reservation);
    }
  }
  return 0;
}

int print_reservations_by_plane(const plane_t *plane) {
  return print_reservations_by_plane_name(plane->name);
}

int print_reservation(reservation_t *reservation) {
  printf("Reservation: {ID: %d, plane %s, seat: %d, surname: %s, name: %s, "
         "status: %s}\n",
         reservation->id, reservation->plane_name, reservation->seat_id,
         reservation->surname, reservation->name,
         get_reservation_status(reservation));
  return 0;
}

int print_reservations() {
  for (int i = 0; i < g_reservation_id; i++) {
    print_reservation(g_reservations[i]);
  }
  printf("\n");
  return 0;
}

int main(int argc, char *argv[]) {
  const int n_seats = 12;
  plane_t *p = create_plane("Boeing", n_seats);
  printf("%s %lu\n", p->name, strlen(p->name));


  int n_reservations = 5;
  printf("Test insert reservation\n");
  for (int i = 0; i < n_reservations; i++) {
    char name[MAX_STRING_LENGTH], surname[MAX_STRING_LENGTH];
    /* Salvo il risultato della stringa formattata in una stringa */
    snprintf(name, MAX_STRING_LENGTH, "Name %d", i);
    snprintf(surname, MAX_STRING_LENGTH, "Surname %d", i);
    int ret_val = insert_reservation(p, i, name, surname);
  }
  print_reservations();
  print_reservations_by_plane_name(p->name);
  printf("\n****\n");

  int n_delete_reservations = 2;
  printf("Test deleting %d reservation\n", n_delete_reservations);
  for (int i = 0; i < n_delete_reservations; i++) {
    int res = delete_reservation(i);
  }
  print_reservations_by_plane_name(p->name);
  printf("\n****\n");

  return 0;
}
