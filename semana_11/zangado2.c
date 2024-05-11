#include <stdio.h>
#include <math.h>

int SomaDosDigitosAoQuadrado(int n){
	int ans,qtd,residuo,aux;

	// Guarda a quantidade de digitos menos 1
	if (n == 0) qtd = 0;
	else qtd = floor(log(n)/log(10));

	// Adiciona na resposta o quadrado dos digitos
	ans = 0;
	residuo = 0;
	for (int i=0; i<=qtd; i++){
		aux = n/floor(pow(10,qtd-i)) - residuo;
		residuo = 10*(aux + residuo);
		ans += aux*aux;
	}

	return ans;
}

int NumeroEhFeliz(int n){
	while (1) { // Loop infinito que serah parado pelos ifs
		if (n == 1) return 1; // Eh numero feliz
		else if (n == 4) return 0; // Convergiu para 4, entao nao eh numero feliz

		n = SomaDosDigitosAoQuadrado(n);
	}
}

int main(){
	int n;

	scanf("%d", &n);

	if (NumeroEhFeliz(n) == 1){
		printf("Zangado estah alegre\n");
	} else {
		printf("Zangado estah sendo um mala\n");
	}

	return 0;
}
