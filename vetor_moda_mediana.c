#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 100

float media();
int moda();
float mediana();

int main(int argc, char const *argv[]) {
  srand( (unsigned)time(NULL) );
  int vetor[LEN];
  for (size_t i = 0; i < LEN; i++) {
    vetor[i] = 1 + (rand() % 500);
  }
  printf("\n");
  printf("Media: %.2f\n", media(vetor));
  printf("Moda: %d\n", moda(vetor));
  printf("Mediana: %.2f\n", mediana(vetor));
  return 0;
}

float media(int vetor[]){
  int soma = 0;
  float media = 0.0;
  for (size_t i = 0; i < LEN; i++) {
    soma += vetor[i];
  }
  media = soma / LEN;
  return media;
}

int moda(int vetor[]){
  int vetor_aux[LEN];
  int x = 0;
  int moda = 0;
  for (size_t i = 0; i < LEN; i++) {
    for (size_t j = i + 1; j < LEN; j++) {
      if(vetor[i] == vetor[j]){
        vetor_aux[i]++;
        if(vetor_aux[i] > x){
          x = vetor_aux[i];
          moda = vetor[i];
        }
      }
    }
  }
  return moda;
}

float mediana(int vetor[]){
  int i = 0;
  float media = 0.0;
  while (i < LEN) { // INSERT SORT
    int k = i;
    while (vetor[k] < vetor[k - 1]) {
      int aux = vetor[k];
      vetor[k] = vetor[k - 1];
      vetor[k - 1] = aux;
      if(k > 1){
        k--;
      }
    }
    i++;
  }
  media = (vetor[LEN/2] + vetor[LEN/2 - 1])/2;
  return media;
}
/* @programador_who */
/*
 aulas particulares de programação - 85 999273805
*/
