#include <stdio.h>
#include <math.h>

typedef struct{
	double x, y;
} Ponto;

void foreach(double M[100][100], int s, int e){
	for (int i=s; i<e; i++){
		for (int j=s; j<e; j++){
			printf("%.2lf ", M[i][j]);
		} printf("\n");
	}
	return;
}

void Prod(double C[100][100], double A[100][100], double B[100][100], int s){
	for (int i=0; i<s; i++){
		for (int j=0; j<s; j++){
			C[i][j] = 0;
			for (int k=0; k<s; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return;
}

void Inv(double A[100][100], double OLD[100][100], int s){
	double I[100][100];

	for (int i=0; i<s; i++){
		for (int j=0; j<s; j++){
			I[i][j] = 0;
			if (i == j) I[i][j] = 1;

			A[i][j] = OLD[i][j];
		}
	}

	for (int j=0; j<s; j++){
		for (int i=0; i<s; i++){
			double elm_diag = A[j][j];
			if (i != j && A[i][j] != 0){
				double mult = -1*(A[i][j])/(elm_diag);
				for (int k=0; k<s; k++){
					A[i][k] += mult*A[j][k];
					I[i][k] += mult*I[j][k];
				}
			}
		}
	}

	for (int i=0; i<s; i++){
		double mult = A[i][i];
		for (int j=0; j<s; j++){
			A[i][j] /= mult;
			I[i][j] /= mult;
			A[i][j] = I[i][j];
		}
	}

	return;
}

#define endl printf("\n");

int main(){
	int grau;
	Ponto P[100];

	printf("Informe o grau da funcao: ");
	scanf("%d", &grau);

	for (int i=0; i<=grau; i++){
		double x,y;
		printf("Informe x e y do %dº ponto da funcao: ", i+1);
		scanf("%lf %lf", &P[i].x, &P[i].y);
	}

	double A[100][100];
	double AT[100][100];
	double ans[100][100];
	double b[100][100];
	for (int i=0; i<=grau; i++){
		for (int j=0; j<=grau; j++) {
			A[i][j] = pow(P[i].x, grau-j);
			AT[j][i] = A[i][j];

			b[i][j] = 0;
			if (j == 0) b[i][j] = P[i].y;
		}
	}

	Prod(ans, AT,A,grau+1); // ans = A^T*A

	printf("Produto:\n");
	foreach(ans, 0, grau+1);

	Inv(A, ans,grau+1); // A = (A^T*A)^(-1)
	printf("\nInversa:\n");
	foreach(A, 0, grau+1);

	Prod(ans, A,AT,grau+1); // ans = (A^T*A)^(-1)*A^T

	Prod(A, ans,b,grau+1); // A = (A^T*A)^(-1)*A^T*b

	printf("\nf(x) = %.2lf*x^(%d)", A[0][0], grau);
	for (int i=1; i<=grau; i++){
		printf(" + (%.2lf)*x^(%d)", A[i][0], grau-i);
	}
	printf("\n");

	return 0;
}
