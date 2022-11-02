#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[] = { 1, 2, 3, 4, 5 };
  int b[][4] = {{2, 4, 6, 8}, {1, 2, 3, 4}};

  int nelems = sizeof(a)/sizeof(a[0]);
  int nrows = sizeof(b) / sizeof(b[0]);
  printf("%d\n", nelems);
  printf("%d\n", nrows);

  return 0;
}
