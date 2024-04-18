#include <stdio.h>

#define MAX_INT 2147483647

int main(){
	int A[30][30], somaL[30], somaC[30], diff, max_lin, min_col, N;

	scanf("%d", &N);

	for (int i=0; i<N; i++){// Zera a soma das linhas e soma das colunas
		somaL[i] = 0;
		somaC[i] = 0;
	}

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d", &A[i][j]); // Le os elementos de cada posicao na matriz A

			somaL[i] += A[i][j]; // Armazena a soma dos elementos de cada linha
			somaC[j] += A[i][j]; // Armazena a soma dos elementos de cada coluna
		}
	}

	for (int k=1; k<N-1; k++){// Itera as diagonais adjacentes a diagonal principal
		for (int i=k-1; i<N-k; i++){ // Itera os elementos das diagonais com simetria na diagonal principal
			if (A[i][i+1] != A[i+1][i]){
				printf("A matriz nao eh simetrica\n");
				return 0;
			}
		}
	}

	diff = 0;
	max_lin = 0;
	min_col = MAX_INT;
	for (int i=0; i<N; i++){
		if (somaL[i] > max_lin) max_lin = somaL[i];
		if (somaC[i] < min_col) min_col = somaC[i];
	}
	diff = max_lin - min_col;

	//Se passou do for, entao a matriz eh simetrica
	printf("A matriz eh simetrica , com diferenca %d\n", diff);

	return 0;
}
