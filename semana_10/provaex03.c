#include <stdio.h>
#include <math.h>

int main(){
	int n, qtd, residuo, valor, tmp;
	char digitos[10];

	do {
		printf("Digite um numero natural para a Permutacao: ");
		scanf("%d", &n);
	} while (n <= 0);

	qtd = floor(log(n)/log(10)); // Quantidade de digitos menos 1: a maxima potencia de 10 que divide n e nao eh um numero nulo

	residuo = 0;
	for (int i=0; i<=qtd; i++){
		digitos[i] = n/floor(pow(10,qtd-i)) - residuo;
		residuo = 10*(digitos[i] + residuo);
	}

	printf("%d", n);
	while (valor != n){
		//Desloca p/ esquerda
		tmp = digitos[0];
		for (int i=0; i<qtd; i++){
			digitos[i] = digitos[i+1];
		}
		digitos[qtd] = tmp;

		// Mostra e retransforma o char[] para um inteiro, para poder comparar com n na verificacao do while
		valor = 0;
		printf(" => ");
		for (int i=0; i<=qtd; i++){
			printf("%d", digitos[i]);
			valor += floor(pow(10,i))*digitos[qtd-i];
		}
	}

	printf("\n");

	return 0;
}
