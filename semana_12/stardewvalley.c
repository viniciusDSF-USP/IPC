#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int index;
	double venda;
	double custo;
	double tempo;
} Planta;

Planta *aloca_plantas(int n) {
	return (Planta *)malloc(n * sizeof(Planta));
}

int main() {
	Planta *p;
	double opd;
	int n;

	// Le quantas plantas serao passadas e aloca o vetor de plantas (p)
	scanf("%d", &n);
	p = aloca_plantas(n);

	// Le os parametros de cada planta
	for (int i=0; i<n; i++){
		scanf("%d %lf %lf %lf", &p[i].index, &p[i].custo, &p[i].venda, &p[i].tempo);
	}

	// Calcula o ouro por dia de cada planta e mostra
	char tabela[][21] = {"empty", "rosa", "margarida", "girassol", "lirio", "dalia", "hibisco",
	"astromelia", "azaleia", "bonina", "hortensia", "mirtilo", "abacaxi", "acerola", "uva", "jabuticaba",
	"tomate", "oxicoco", "carambola", "cacau", "figo"};

	for (int i=0; i<n; i++){
		// opd = (venda - custo) * (piso(28/tempo) <-- qtd. / 28)
		opd = (p[i].venda - p[i].custo) * ( floor(28/p[i].tempo) / 28 );
		printf("%s: %.2lf o/d\n", tabela[p[i].index], opd);
	}

	// Libera a memoria do ponteiro
	free(p);

	return 0;
}
