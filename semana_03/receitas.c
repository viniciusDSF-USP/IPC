// Programa que le de qual comida a pessoa quer a receita
// e mostra a receita correspondente. Esta faltando colocar
// o link das receitas.

#include <stdio.h>

int main() {
	int comida;

	// Mostra as opcoes de receitas
	printf("Livro de receitas:\n1. Arroz;\n2. Feijao;\n3. Bolo de cenoura;\n4. Miojo;\n5. Macarrao.\n");

	// Pede e le o numero correspondente a receita desejada
	printf("Digite o numero da comida que voce quer a receita:\n");
	scanf("%d", &comida);

	// Analisa o numero digitado e mostra a receita correspondente.
	switch (comida) {
	case 1:
		printf("https://www.tudogostoso.com.br/receita/770-arroz-branco.html\n");
		break;
	case 2:
		printf("https://www.tudogostoso.com.br/receita/169692-feijao.html\n");
		break;
	case 3:
		printf("https://www.tudogostoso.com.br/receita/23-bolo-de-cenoura.html\n");
		break;
	case 4:
		printf("\n");
		printf("https://pt.wikihow.com/Fazer-Miojo-de-Jeitos-Diferentes (crie vergonha na cara!)\n");
		break;
	case 5:
		printf("https://www.tudogostoso.com.br/receita/101040-macarrao-simples.html\n");
		break;
	default:
		//printf("Nao tenho essa receita, vai ficar com fome >:( ou peca comida\n");
		printf("Nao tenho essa receita, mas voce deve gostar desta:\nhttps://viniciusdsf-usp.github.io/IPC/semana_03/Receita%20de%20ur%C3%A2nio%20enriquecido%20-%20TudoGostoso.html >:D\n");
	}

	// Mostra uma mensagem final.
	printf("Bom apetite!\n");

	return 0;
}
