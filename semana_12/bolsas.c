#include <stdio.h>
#include <stdlib.h>

int main() {
	int bolsas, alunos, *quali;
	int reprov, ant_r;
	double media, ant_m;
	int ultimo, qtd;

	scanf("%d %d", &bolsas, &alunos);

	// Alocando a qtd de alunos para as notas
	quali = (int *)malloc(alunos*sizeof(int));

	// Lendo as reprovacoes e medias e guardando os qualificados
	ant_r = -1;
	ant_m = -1;
	for (int i=0; i<alunos; i++) {
		scanf("%d %lf", &reprov, &media);

		if (bolsas > 0){ // Enquanto tiver bolsas
			if ((media > reprov) || ((media > 8) && (reprov < 10))) {
				quali[i] = 1; // Qualificado
				ant_r = reprov;
				ant_m = media;
				bolsas--;
			}
		} else if (reprov == ant_r && media == ant_m) { // Se tiver empate
			quali[i] = 1;
		} else {
			quali[i] = 0; // Nao qualificado
			ant_r = -1;
			ant_m = -1;
		}
	}

	// Mostrando quantidade de qualificados e a posicao do ultimo qualificado
	ultimo = -1;
	qtd = 0;
	for (int i=0; i<alunos; i++) {
		if (quali[i] == 1) {
			ultimo = i+1; // Se o ultimo for o 0, entao eh o aluno numero 1 que eh i+1
			qtd++;
		}
	}

	printf("%d alunos foram qualificados.", qtd);
	if (ultimo > -1) printf(" O ultimo qualificado foi o aluno numero %d", ultimo);
	printf("\n");

	return 0;
}
