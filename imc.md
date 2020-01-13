% Índice de Massa Corporal - IMC
% Paulino Ng
% 2019-09-19

# IMC

O **IMC** é um indicador internacional usado para determinar se uma pessoa está
com o peso ideal. Ele é calculado pela fórmula:

IMC = massa/(altura . altura)

Para massa dada em **kg** (quilogramas) e altura em **m** (metros), vale a
tabela abaixo:

| Resultado | Situação |
|-----------|----------|
| IMC < 17  | Muito abaixo |
| 17 <= IMC < 18,5 | Abaixo |
| 18,5 <= IMC < 25 | Normal |
| 25 <= IMC < 30 |  Acima |
| 30 <= IMC < 35 | Obesidade I |
| 35 <= IMC < 40 | Obesidade II |
| IMC >= 40 | Obesidade III |

Fonte: [IMC](https://pt.wikipedia.org/wiki/%C3%8Dndice_de_massa_corporal)

A **obesidade II** é considerada severa e a **obesidade III** é considerada
mórbida. Ambos indicam a necessidade de acompanhamento médico.

## Programa que imprime seu status quanto ao IMC

### Em Python

```Python
def imc(a,m): return m / (a * a)

def diagnoticoIMC(imc):
    if imc < 17: return 'Muito abaixo do normal'
    elif 17 <= imc < 18.5: return 'Abaixo do normal'
    elif 18.5 <= imc < 25: return 'Normal'
    elif 25 <= imc < 30: return 'Acima do normal'
    elif 30 <= imc < 35: return 'Obesidade I'
    elif 35 <= imc < 40: return 'Obesidade II'
    else:
      return 'Obesidade III'

altura = float(input('Sua altura: '))
massa = float(input('Seu peso: '))
print(diagnostico(imc(altura, massa)))
```

### Em C

```C
#include <stdio.h>

float imc(float a, float m);
char *diagnosticoIMC(float imc);

const char **diags = {"Muito abaixo do normal",
                      "Abaixo do normal",
                      "Normal",
                      "Acima do normal",
                      "Obesidade I",
                      "Obesidade II",
                      "Obesidade III"};

float imc(float a, float m) {
  return m/(a*a);
}

char *diagnosticoIMC(float imc) {
  if (imc < 17) return diags[0];
  else if (imc < 18.5) return diags[1];
  else if (imc < 25) return diags[2];
  else if (imc < 30) return diags[3];
  else if (imc < 35) return diags[4];
  else if (imc < 40) return diags[5];
  else return diags[6];
}

int main() {
  float a, m;
  printf("Sua altura: ");
  scanf("%f", &a);
  printf("Seu peso: ");
  scanf("%f", &m);
  printf("Seu peso esta: %s\n", diagnosticoIMC(imc(a, m)));
  return 0;
}
```
