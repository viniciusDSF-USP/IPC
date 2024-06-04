#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double a,b,c,d,e,f;
} conica;

int main(){
	conica coef;

	printf("Informe os coeficientes a,b,c,d,e,f da equacao ax²+bxy+cy²+dx+ey+f=0: ");
	scanf("%lf %lf %lf %lf %lf %lf", &coef.a, &coef.b, &coef.c, &coef.d, &coef.e, &coef.f);

	return 0;
}
