#include <stdio.h>

int main(){
	// n: linhas
	// m: colunas
	// d: deslocamento
	int n,m,d;
	char televisao[100][100],aux,aux2;

	scanf("%d %d %d", &n, &m, &d);

	// Lendo os caracteres da televisao
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf(" %c", &televisao[i][j]);
		}
	}

	// Removendo o deslocamento
	for (int k=0; k<m-d; k++){
	// Desfaz o deslocamento de d ao repetir o deslocamento unitario para a direita (m-d) vezes
		for (int i=0; i<n; i++){
			for (int j=0; j<m-1; j++){ // Da primeira coluna ate a penultima
				if (j == 0){
					aux = televisao[i][j+1]; // Guarda a proxima coluna original para a proxima iteracao
					televisao[i][j+1] = televisao[i][j];

					televisao[i][j] = televisao[i][m-1]; // Troca a primeira pela ultima
				} else {
					aux2 = televisao[i][j+1]; // Guarda a proxima coluna original para a proxima iteracao
					televisao[i][j+1] = aux; // Usa a coluna original da iteracao anterior
					aux = aux2;
				}
			}
		}
	}

	// Mostrando a televisao sem o deslocamento
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%c", televisao[i][j]);
		}
		printf("\n");
	}

	return 0;
}
