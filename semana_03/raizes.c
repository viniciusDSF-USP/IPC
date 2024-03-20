// Programa que le os coeficientes de uma equacao de
// segundo grau ax^2 + bx + c = 0 e calcula suas
// raizes reais.

#include <stdio.h>
#include <math.h>

int main() {
	//x1_imag e x2_imag sao a parte imaginaria de x1 e x2, respectivamente, se houver
    float a, b, c, delta, x1, x2, x1_imag, x2_imag;

    // Le o coeficiente de x^2 da equacao
    printf("A equacao que vamos resolver eh ax^2 + bx + c = 0, com a,b,c numeros reais\n");

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

	if (a == 0 && b != 0){ // Raiz de equacao de primeiro grau
		x1 = -c/b;
		printf("A raiz da equacao eh: x = %.2f\n", x1);
	} else if (a == 0 && b == 0) { // Testa se c = 0
		if (c == 0) printf("Verdadeiro\n");
		else printf("Falso\n");
	} else { // Raiz(es) de equacao de segundo grau
	    // Calcula o valor de delta
	    delta = b * b - 4 * a * c;

	    // Calcula as raizes
	    if (delta < 0) {
			x1 = (-b) / (2 * a);
			x1_imag = sqrt((-1)*delta) / (2*a); // x2_imag = x1_imag sempre, porque separa-se a parte imaginaria

			printf("As raizes da equacao sao complexas e valem: x1 = %.2f + %.2fi e x2 = %.2f - %.2fi\n", x1, x1_imag, x1, x1_imag);
	    }
	    else {
	        // Se o delta eh 0, soh calcula uma raiz (as duas sao iguais)
	        if (delta == 0) {
	            x1 = (-b + sqrt(delta)) / (2 * a);
	            printf("As raizes sao iguais e valem %.2f\n", x1);
	        }
	        else {
	            // Neste caso, delta eh positivo e calcula as 2 raizes
	            x1 = (-b + sqrt(delta)) / (2 * a);
	            x2 = (-b - sqrt(delta)) / (2 * a);
	            printf("As raizes da equacao sao: x1 = %.2f e x2 = %.2f\n", x1, x2);
	        }
	    }
	}

    return 0;
}
