#include <stdio.h>

typedef struct _pessoa{
	double altura, forca, idade;
	char tipo;
} pessoa;

int main(){
	pessoa Cheer[1000];
	int n;
	double maior, qualidade;

	scanf("%d", &n);

	// Guarda os n-esimos dados dos flyers e dos bases
	for (int i=0; i<n; i++){
		scanf("%lf %lf %lf %c", &Cheer[i].altura, &Cheer[i].forca, &Cheer[i].idade, &Cheer[i].tipo);
	}

	// Verifica as duplas para escolher a melhor
	maior = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (Cheer[i].tipo == 'B' && Cheer[j].tipo == 'F'){
				// Combina bases com flyers
				// qualidade = base.idade * flyer.altura * (base.forca + flyer.forca)
				qualidade = Cheer[i].idade * Cheer[j].altura * (Cheer[i].forca + Cheer[j].forca);
				if (qualidade > maior) maior = qualidade;
			}
		}
	}

	printf("%.2lf\n", maior);

	return 0;
}
