#include <stdio.h>
#include <stdlib.h>

int main(){
	double A[10][10], AI[10][10], elm_diag, razao;
	int n, redo;

	printf("Informe a ordem da matriz quadrada: ");
	scanf("%d", &n);

	do {
		redo = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				printf("Informe o elemento (%d,%d): ",i+1,j+1);
				scanf("%lf", &A[i][j]);

				AI[i][j] = 0;
				if (i == j) AI[i][j] = 1; //Comecando AI como a matriz identidade de ordem n
			}
		}

		for (int j=0; j<n; j++){
			if (redo == 1) break;
			for (int i=0; i<n; i++){
				elm_diag = A[j][j];

				if (elm_diag == 0){
					printf("O determinante eh nulo! Nao ha matriz inversa se o determinante eh nulo.\n");
					redo = 1;
					break;
				}

				if (i != j){ // Nao eh um elemento da diagonal principal
					if (A[i][j] != 0){
						razao = -1*(A[i][j])/(elm_diag);

						for (int k=0; k<n; k++){
							A[i][k] += razao*A[j][k];
							AI[i][k] += razao*AI[j][k];
						}
					}
				}
			}
		}
		if (redo == 1) {
			char res;
			printf("Quer tentar novamente? (s/n) ");
			scanf(" %c", &res);
			if (res == 's') system("clear");
			else return 0;
		}
	} while(redo == 1);

	printf("\nMatriz de inversa por reducao Gaussiana:\n");
	for (int i=0; i<n; i++){
		razao = A[i][i];
		for (int j=0; j<n; j++){
			A[i][j] /= razao;
			AI[i][j] /= razao;

			printf("%12.6lf ", AI[i][j]);
		}
		printf("\n");
	}

	return 0;
}
