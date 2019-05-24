#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 4
#define C 4
int determinante();
int multiplicacao();

int main(int argc, char const *argv[]) {
  srand( (unsigned)time(NULL) );
  int matriz_a[L][C];
  int matriz_b[L][C];
  for (size_t i = 0; i < L; i++) {
    for (size_t j = 0; j < C; j++) {
      matriz_a[i][j] = 1 + (rand() % 9);
      matriz_b[i][j] = 1 + (rand() % 9);
    }
  }
  for (size_t i = 0; i < L; i++) {
    for (size_t j = 0; j < C; j++) {
      printf("%d ", matriz_a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (size_t i = 0; i < L; i++) {
    for (size_t j = 0; j < C; j++) {
      printf("%d ", matriz_b[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Determinante %d\n", determinante(matriz_a));
  printf("Determinante %d\n", determinante(matriz_b));
  printf("\nMultiplicacao:\n");
  multiplicacao(matriz_a, matriz_b);
  return 0;
}

int determinante(int matriz[L][C]){
  int matriz_aux[L][C+2];
  for (size_t i = 0; i < L; i++) {
    for (size_t j = 0; j < (C + 2); j++) {
      if(j > 3){matriz_aux[i][j] = matriz[i][j - 4];}
      else{matriz_aux[i][j] = matriz[i][j];}
    }
  }
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 3;
  int count = 0;
  int soma_diag_prin = 0;
  int soma_diag_sec = 0;
  int mult_diag_prin = 1;
  int mult_diag_secu = 1;
  while (count < 3) {
    while (i < L) {
      mult_diag_prin *= matriz_aux[i][j];
      mult_diag_secu *= matriz_aux[l - i][j];
      i++;
      j++;
    }
    count++;
    i = 0;
    k++;
    j = k;
    soma_diag_prin += mult_diag_prin;
    soma_diag_sec += mult_diag_secu;
    mult_diag_prin = 1;
    mult_diag_secu = 1;
  }
  return soma_diag_prin - soma_diag_sec;
}

int multiplicacao(int matriz_a[L][C], int matriz_b[L][C]){
  int matriz_r[L][C]; int linha = 0; int coluna = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int aux_colun = 0;
  int soma = 0;
  while (i < L) {
    while (j < L) {
      while (k < C) {
        soma += matriz_a[i][k] * matriz_b[k][aux_colun];
        k++;
      }
      k = 0;
      j++;
      matriz_r[linha][coluna] = soma;
      soma = 0;
      coluna++;
      aux_colun++;
    }
    i++;
    linha++;
    coluna = 0;
    j = 0;
    aux_colun = 0;
  }

  for (size_t i = 0; i < L; i++) {
    for (size_t j = 0; j < C; j++) {
      printf("%d\t", matriz_r[i][j]);
    }
    printf("\n");
  }

  return 0;
}
/* @programador_who */
/*
 aulas particulares de programação - 85 999273805
*/
