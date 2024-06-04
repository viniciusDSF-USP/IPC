#include <stdio.h>
#include <stdlib.h>

void zera(int *vec, int n){
	for (int i=0; i<n; i++){
		vec[i] = 0;
	}

	return;
}

int recursao(double *posto, double *dist, int *visitado, int pos, int fim, double gasolina){
	if (visitado[pos] == 1) return 1;

	if (gasolina < 0) return 0;
	else gasolina += posto[pos];
	visitado[pos] = 1;

	int next = (pos+1)%fim;
	return recursao(posto, dist, visitado, next, fim, gasolina-dist[pos]); // dist[pos]: d(pos, next)
}

int main(){
	int n, somaDist, somaGas, *visitado;
	double *posto, *distancia;

	printf("Quantidade de postos: ");
	scanf("%d", &n);

	posto = (double *) malloc(n*sizeof(double));
	distancia = (double *) malloc(n*sizeof(double));
	visitado = (int *) malloc(n*sizeof(int));
	if (posto == NULL || visitado == NULL || distancia == NULL) {
		printf("Erro: Memoria insuficiente!");
		return 8;
	}

	somaDist = 0;
	somaGas = 0;
	for (int i=0; i<n; i++){
		printf("Quantidade de gasolina no %dº posto (litros): ", i+1);
		scanf("%lf", &posto[i]);
		somaGas += posto[i];

		if (i < n-1) printf("Distancia entre o %dº posto e o %dº posto (km): ", i+1, i+2);
		else printf("Distancia entre o %dº posto e o 1º posto (km): ", n);
		scanf("%lf", &distancia[i]); // distancia[0]: d(0,1)
		somaDist += distancia[i];

		printf("\n");
	}

	printf("\n");
	if (somaGas >= somaDist) {
		zera(visitado, n);

		for (int i=0; i<n; i++){
			if (recursao(posto, distancia, visitado, i, n, 0) == 1){
				printf("É possível dar a volta, partindo do %dº posto.\n", i+1);
			}
			zera(visitado, n);
		}
	} else {
		printf("IMPOSSIVEL!\n");
	}

	return 0;
}
