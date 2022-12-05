/*
 * TAGS: struct, typedef, function, pointer
 *
 * NOTES: struct passed by value
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PLAYERS 2
#define MAX_STRING_LENGTH 20
#define MAX_ITERS 100

typedef struct {
  char name[MAX_STRING_LENGTH];
  unsigned short fight_ability;
  float energy;
} player;

void printPlayer(player p) {
  printf("Player %s: ability = %d, energy = %5.2f\n", p.name, p.fight_ability,
         p.energy);
}

player createPlayer() {
  player p;

  printf("Name: ");
  scanf("\n%s", p.name);
  do {
    printf("Fight ability (0-100): ");
    scanf("\n%hu", &p.fight_ability);
  } while (p.fight_ability < 0 || p.fight_ability > 100);

  p.energy = 100;
  printf("Player created\n");
  return p;
}

int fight(player p1, player p2, short eps) {
  player *better, *worse;
  short abil_diff = p1.fight_ability - p2.fight_ability;

  for (int i = 0; i < MAX_ITERS; i++) {
    if (abil_diff > eps) {
      printf("Player 1 better\n");
      better = &p1;
      worse = &p2;
    } else if (abil_diff < -eps) {
      printf("Player 2 better\n");
      better = &p2;
      worse = &p1;
      abil_diff *= -1;
    } else {
      printf("Player tie, pick a random better/worse\n");
      abil_diff = 5;
      if (rand() > 0.5) {
        better = &p1;
        worse = &p2;
      } else {
        better = &p2;
        worse = &p1;
      }
    }

    better->energy -= abil_diff / 10;
    worse->energy -= abil_diff / 3;
    printPlayer(p1);
    printPlayer(p2);

    if (p1.energy <= 0)
      return 1;
    if (p2.energy <= 0)
      return 2;
  }
  return 0;
}

int main() {
  srand(time(NULL));
  player p1, p2;
  int res;

  p1 = createPlayer();
  p2 = createPlayer();
  res = fight(p1, p2, 5);
  printf("Player %d won\n", res);
  return 0;
}
