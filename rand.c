#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("rand de 0 a %d = %d\n",  RAND_MAX, rand());
  int i;
  for (i = 0; i < 30; i++)
    printf("rand de -10 a 20 = %d\n", rand() % (20 - (-10) + 1) -10);
  return 0;
}
