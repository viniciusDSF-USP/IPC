#include <stdio.h>

int main(){
	int ddd, valido;
	char telefone[11];

	for (int i=0; i<11; i++){
		scanf("%c", &telefone[i]);
		telefone[i] -= '0'; // Converte o i-esimo char para um int no intervalo [0-9]
	}

	//Verificando o DDD
	ddd = 10*telefone[0] + telefone[1]; // Converte os dois primeiros digitos para um unico int
	if (ddd < 11 || ddd > 19){
		valido = 0;
	} else {
		valido = 1;
	}

	if (valido == 1){
		if ((telefone[2] != 9) || (telefone[3] < 5)){ // Verifica o digito 3 e 4
			valido = 0;
		} else {
			for (int i=4; i<11; i++){ // Verifica os digitos 5 em diante se ha pelo menos um nao-nulo
				if (telefone[i] != 0){
					valido = 1;
					break;
				} else {
					valido = 0;
				}
			}
		}
	}

	if (valido == 0){
		printf("O numero nao existe\n");
	} else {
		printf("O numero existe\n");
	}

	return 0;
}
