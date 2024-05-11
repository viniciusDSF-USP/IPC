// Programa que le o numero de linhas e colunas e de uma matriz M1,
// os elementos de M1, o numero de colunas de uma matriz M2 (que
// tem o numero de linhas igual ao numero de linhas de M1), os
// elementos de M2, e calcula o produto P = M1 * M2.

#include <stdio.h>

int main() {
  double M1[10][10],M2[10][10],P[10][10];
  int i,j,k,linha_M1,coluna_M1,linha_M2,coluna_M2;

  // Le a quantidade de linhas da matriz M1
  do {
    printf("Digite o numero de linha da matriz M1 (entre 1 e 10): ");
    scanf("%d", &linha_M1);
  } while(linha_M1 < 1 || linha_M1 > 10);

  // Le a quantidade de colunas da matriz M1
  do {
    printf("Digite o numero de colunas da matriz M1 (entre 1 e 10): ");
    scanf("%d", &coluna_M1);
  } while(coluna_M1 < 1 || coluna_M1 > 10);

  // Le os elementos da primeira matriz (M1)
  for (i = 0; i < linha_M1; i++) {
    for (j = 0; j < coluna_M1; j++) {
      printf("Digite o elemento (%d,%d) da matriz M1: ", i+1, j+1);
      scanf("%lf", &M1[i][j]);
    }
  }

  // Mostra a primeira matriz (M1)
  printf("M1 =\n");
  for (i = 0; i < linha_M1; i++) {
    for (j = 0; j < coluna_M1; j++) {
      printf("%10.2lf ", M1[i][j]);
    }
    printf("\n\n");
  }
  
  // Le a quantidade de colunas da matriz M2
  do {
    printf("Digite o numero de colunas da matriz M2 (entre 1 e 10)\nO numero de linha de M2 eh %d: ", coluna_M1);
    scanf("%d", &coluna_M2);
  } while(coluna_M2 < 1 || coluna_M2 > 10);

  // O numero de linhas de M2 eh igual ao numero de colunas de M1.
  linha_M2 = coluna_M1;
  
  // Le os elementos da segunda matriz (M2).
  for (i = 0; i < linha_M2; i++) {
    for (j = 0; j < coluna_M2; j++) {
      printf("Digite o elemento (%d,%d) da matriz M2: ", i+1, j+1);
      scanf("%lf", &M2[i][j]);
    }
  }

  // Mostra a segunda matriz (M2)
  printf("M2 =\n");
  for (i = 0; i < linha_M2; i++) {
    for (j = 0; j < coluna_M2; j++) {
      printf("%10.2lf ", M2[i][j]);
    }
    printf("\n\n");
  }

  // Calcula o produto P = M1 * M2
  for (i = 0; i < linha_M1; i++) {
    for (j = 0; j < coluna_M2; j++) {
      P[i][j] = 0;
      for (k = 0; k < coluna_M1; k++){
	P[i][j] = P[i][j] + M1[i][k]*M2[k][j];
      }
    }
  }

  // Mostra o resultado do produto (P)
  printf("P =\n");
  for (i = 0; i < linha_M1; i++) {
    for (j = 0; j < coluna_M2; j++) {
      printf("%10.2lf ", P[i][j]);
    }
    printf("\n\n");
  }
  
  return(42);
}
