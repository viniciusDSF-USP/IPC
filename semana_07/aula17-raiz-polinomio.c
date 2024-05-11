// Programa que le o grau e os coeficientes de um polinomio P
// e um numero x e calcula uma raiz de P (usando o Metodo da
// Bisseccao).

#include <stdio.h>
#include <math.h>

int main() {
  int grau,cont;
  double P[101],x_mais,x_menos,x_meio,P_x_mais,P_x_menos,P_x_meio,pow_x;

  // Le o grau do polinomio P, que precisa estar entre 0 e 100
  do {
    printf("Digite o grau do polinomio (entre 0 e 100): ");
    scanf("%d", &grau);
  } while(grau < 0 || grau > 100);
  
  // Le os coeficientes do polinomio P
  for (cont = 0; cont <= grau; cont++) {

    printf("Digite o coeficiente de x^%d: ", cont);
    scanf("%lf", &P[cont]);
  }

  // Mostra o polinomio P
  printf("P(x) = ");
  for (cont = grau; cont >= 0; cont--) {
  	if (P[cont] != 0){
	  if (cont != grau && P[cont] > 0){
      	printf("+ ");
      } else if (P[cont] < 0){
      	printf("- ");
      }

      if (fabs(P[cont]) != 1) {
     	printf("%.1lf",fabs(P[cont]));
      }

      if (cont > 1) printf("x^%d ", cont);
      else if (cont == 1) printf("x ");
      else printf(" ");
    }
  }
  printf("\n");

  // Le o valor de x_mais (P(x_mais) > 0)
  do {
    printf("Digite o valor de x (tal que P(x) > 0): ");
    scanf("%lf", &x_mais);

    // Calcula o valor de P(x_mais)
    P_x_mais = 0;
    pow_x = 1;
    for (cont = 0; cont <= grau; cont++) {
      P_x_mais = P_x_mais + P[cont]*pow_x;
      pow_x = pow_x * x_mais;
    }

    printf("P(%.1lf) = %.1lf\n", x_mais, P_x_mais);
  } while(P_x_mais <= 0);
 
  // Le o valor de x_menos (P(x_menos) < 0)
  do {
    printf("Digite o valor de x (tal que P(x) < 0): ");
    scanf("%lf", &x_menos);

    // Calcula o valor de P(x_menos)
    P_x_menos = 0;
    pow_x = 1;
    for (cont = 0; cont <= grau; cont++) {
      P_x_menos = P_x_menos + P[cont]*pow_x;
      pow_x = pow_x * x_menos;
    }

    printf("P(%.1lf) = %.1lf\n", x_menos, P_x_menos);
  } while(P_x_menos >= 0);

  // Calcula x_meio no meio de x_mais e x_menos
  x_meio = (x_mais + x_menos)/2;
  
  // Calcula P(x_meio)
  P_x_meio = 0;
  pow_x = 1;
  for (cont = 0; cont <= grau; cont++) {
    P_x_meio = P_x_meio + P[cont]*pow_x;
    pow_x = pow_x * x_meio;
  }

  // Calcula uma raiz de P, usando o Metodo da Bisseccao
  while (fabs(P_x_meio) > 1.0e-4) {
    
    // Mostra o valor de P(x_meio)
    printf("P(%.6lf) = %.6lf\n", x_meio, P_x_meio);

    // Atualiza x_mais ou x_menos
    if (P_x_meio > 0) {
      x_mais = x_meio;
    }
    else {
      x_menos = x_meio;
    }

    // Calcula x_meio no meio de x_mais e x_menos (atualizados)
    x_meio = (x_mais + x_menos)/2;
    
    // Calcula P(x_meio)
    P_x_meio = 0;
    pow_x = 1;
    for (cont = 0; cont <= grau; cont++) {
      P_x_meio = P_x_meio + P[cont]*pow_x;
      pow_x = pow_x * x_meio;
    }
  }
  
  // Mostra a raiz encontrada de P
  printf("Uma raiz de P eh %.6lf\nP(%.6lf) = %.6lf\n", x_meio, x_meio, P_x_meio);
  
  return(42);
}
