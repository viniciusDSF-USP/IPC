#include <stdio.h>

int main(){
	double A[10][10], elm_diag, razao, det;
	int n;

	printf("Informe a ordem da matriz quadrada: ");
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("Informe o elemento (%d,%d): ",i+1,j+1);
			scanf("%lf", &A[i][j]);
		}
	}

	for (int j=0; j<n; j++){
		for (int i=0; i<n; i++){
			elm_diag = A[j][j];

			if (i != j){ // Nao eh um elemento da diagonal principal
				if (A[i][j] != 0){
					razao = -1*(A[i][j])/(elm_diag);
					for (int k=0; k<n; k++){
						A[i][k] += razao*A[j][k];
					}
				}
			}
		}
	}

	printf("\nMatriz de reducao Gaussiana:\n");
	det = 1;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%4.1lf ", A[i][j]);
		}
		printf("\n");
		det *= A[i][i];
	}

	printf("\nDeterminante: %.2lf\n", det);

	return 0;
}
