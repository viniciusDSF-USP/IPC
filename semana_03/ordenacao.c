#include <stdio.h>

int main(){
	//Short int para ocupar menos memoria, tendo em vista a restricao no intervalo [-100, 100]
	short int a, b, c;
	//Inteiros para armazenar os elementos da sequencia ordenada
	short int x, y, z;

	//Aqui e no resto do programa usei %hd porque eh short int
	scanf("%hd %hd %hd", &a, &b, &c);

	printf("Sequencia original: %hd %hd %hd\n", a, b, c);

	if (a == b && a == c){//Se a,b,c sao todos iguais, ja estao ordenados
		//Aqui eh arbitrario escolher x como a, b ou c
		x = a;
		y = a;
		z = a;
	} else { //Todas as comparacoes possiveis para a,b,c nao todos iguais
		//Verificacao do menor elemento da sequencia
		if (a < b && a < c) x = a;
		else if (b < a && b < c) x = b;
		else if (c < a && c < b) x = c;
		else if (a == b || a == c) x = a; //Aqui eh arbitrario escolher x como a ou c
		else if (b == c) x = b; //Aqui eh arbitrario escolher x como b ou c

		//Verificacao do terceiro (maior) elemento da sequencia
		if (a > b && a > c) z = a;
		else if (b > a && b > c) z = b;
		else if (c > a && c > b) z = c;
		else if (a == b || a == c) z = a;
		else if (b == c) z = b;

		//Verificacao do segundo menor elemento da sequencia
		if (a > x && a < z) y = a;
		else if (b > x && b < z) y = b;
		else if (c > x && c < z) y = c;
		else if (a == x && a != z) y = a;
		else if (b == x && b != z) y = b;
		else if (c == x && c != z) y = c;
	}

	printf("Sequencia ordenada: %hd %hd %hd", x, y, z);

	return 0;
}
