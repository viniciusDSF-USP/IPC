#include <stdio.h>

int main(){
	int linhas;
	unsigned int num; // Como num eh um natural, nunca vai ser negativo, logo unsigned

	num = 1; // O primeiro natural vai ser o 1
	scanf("%d", &linhas);


	if (linhas < 1) printf("Este nao eh um numero natural valido\n");
	else {
		for (int t=0; t<linhas; t++){//Itera as linhas do triangulo
			for (int i=0; i<t+1; i++){//Itira os numeros da linha ate ter um numero de elementos numericamente igual a linha (ex.: a 2a linha tem 2 elementos)
				printf("%3d ", num);
				num++;
			}
			printf("\n");
		}
	}

	return 0;
}
