#include <stdio.h>
int main() {
  float erro1 = 0.0F;
  double erro2 = 0.0;
  int i;
  for (i = 0; i < 10; i++) {
    erro1 += 0.1F;
    erro2 += 0.1;
  }
  erro1 -= 1.0F;
  erro2 -= 1.0;
  printf("Erro com float = %g\terro com double = %g\n", erro1, erro2);
  return 0;
}