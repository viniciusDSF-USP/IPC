#include <stdio.h>
#include <math.h>

typedef long long int ll;

typedef struct {
	int base;
	ll valor;
} Ingresso;

ll binarioParaBase10(ll preco) {
	ll decimal;

	decimal = 0;
	for (int i=0; i<=10; i++){
		if (preco % 2 == 1){ // Se acabar com 1
			decimal += pow(2, i);
		}
		preco = preco/10; // Desloca para esquerda
	}

	return decimal;
}

ll menorPreco(Ingresso precos[100], int size) {
	Ingresso aux;

	for (int i=0; i<size; i++){ // Converte os binarios para decimal
		if (precos[i].base == 2){
			precos[i].base = 10;
			precos[i].valor = binarioParaBase10(precos[i].valor);
		}
	}

	for (int bbsort=0; bbsort<size-1; bbsort++){ // Ordena em ordem crescente por Bubble Sort
		for (int j=0; j<size-1; j++){
			if (precos[j].valor > precos[j+1].valor){
				aux = precos[j];
				precos[j] = precos[j+1];
				precos[j+1] = aux;
			}
		}
	}

	return precos[0].valor; // O primeiro elemento eh o menor de todos, porque estah em ordem crescente
}

int main(){
	Ingresso precos[100];
	int n;

	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf("%d %lld", &precos[i].base, &precos[i].valor);
	}

	printf("%lld\n", menorPreco(precos, n));

	return 0;
}
