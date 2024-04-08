#include <stdio.h>

int main(){
	double N, maior, menor;
	int qtd;

	qtd = 0;
	menor = 1E10+1; //10.001, maior valor de todos porque o maximo valor de N eh 10.000
	maior = 0;

	do {
		scanf("%lf", &N);

		//Verificacao para nao adicionar um a
		// mais no qtd e nao atribuir o negativo
		// ao N na ultima iteracao, porque a verificacao soh ocorre no final
		if (N > -1){
			if (N > maior) maior = N;
			if (N < menor) menor = N;
			qtd++;
		}
	} while(N > -1);

	if (menor == 10E10+1) {// Significa que nao entrou no while, logo o unico N eh igual a -1
		menor = 0;
	}

	printf("%d\n%.2lf\n%.2lf\n", qtd, maior, menor);

	return 0;
}
