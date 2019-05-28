#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define Q_A 50

int main(int argc, char const *argv[]) {

  srand( (unsigned)time(NULL) );
  int aluno[Q_A];
  for (size_t i = 0; i < Q_A; i++) {
    aluno[i] = (rand() % 11);
  }
  for (int i = 10; i > 0; i--) {
    printf("%d = ", i);
    for (size_t j = 0; j < Q_A; j++) {
      if(aluno[j] == i){
        printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}
/* @programador_who */
/*
 aulas particulares de programação - 85 999273805
*/
