#include <stdio.h>
#include <stdlib.h>

#define EMPTY	'*'

int min(short int a, int b){
	if (a < b) return a;
	else return b;
}

int minPositivo(short int a, int b){
	if (a < b && a >= 0) return a;
	else return b;
}

int max(short int a, int b){
	if (a > b) return a;
	else return b;
}

int Afogou(short int p1[8][8], short int p2[8][8], int x, int y, int player){
	//Verificando se o p1 afogou
	if (player == 1){
		int afog_p1 = 0;
		if (p1[x][y] == 1 || p2[x][y] == 1) afog_p1 = 1;
		else {
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					afog_p1 = 1; // Pressupomos que vai afogar
					if ((i != x || j != y) && (p1[i][j] == 1)){
						if (i == x && abs(y-j) > 1){
							//Mesma linha
							int continua=1;

							for (int k=min(y,j)+1; k<max(y,j); k++){
								if (p2[x][k] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p1 = 0;

						} if (j == y && abs(x-i) > 1) {
							//Mesma coluna
							int continua=1;
							
							for (int k=min(x,i)+1; k<max(x,i); k++){
								if (p2[k][y] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p1 = 0;

						} if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
							//Em alguma diagonal de (x,y)
							short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
							short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

							int continua=1;

							for (int k=1; k<abs(x-i); k++){
								if (p2[x+k*norm_x][y+k*norm_y] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p1 = 0;

						}
					}

					if (afog_p1 == 0) { // Se tiver pelo menos uma jogada possivel
						afog_p1 = -1;
						break;
					}
				}
				if (afog_p1 == -1) { // Break recursivo
					afog_p1 = 0;
					break;
				}
			}
		}

		if (afog_p1 == 1) return 1;
		else return 0;

	} else{
		//Verificando se o p2 afogou
		int afog_p2 = 0;
		if (p1[x][y] == 1 || p2[x][y] == 1) afog_p2 = 1;
		else {
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					afog_p2 = 1; // Pressupomos que vai afogar
					if ((i != x || j != y) && (p2[i][j] == 1)){
						if (i == x && abs(y-j) > 1){
							//Mesma linha
							int continua=1;

							for (int k=min(y,j)+1; k<max(y,j); k++){
								if (p1[x][k] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p2 = 0;

						} if (j == y && abs(x-i) > 1) {
							//Mesma coluna
							int continua=1;
							
							for (int k=min(x,i)+1; k<max(x,i); k++){
								if (p1[k][y] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p2 = 0;

						} if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
							//Em alguma diagonal de (x,y)
							short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
							short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

							int continua=1;

							for (int k=1; k<abs(x-i); k++){
								if (p1[x+k*norm_x][y+k*norm_y] == 0){
									continua = 0;
									break;
								}
							}
							if (continua == 1) afog_p2 = 0;
						}
					}
					if (afog_p2 == 0) { // Se tiver pelo menos uma jogada possivel
						afog_p2 = -1;
						break;
					}
				}
				if (afog_p2 == -1) { // Break recursivo
					afog_p2 = 0;
					break;
				}
			}
		}

		if (afog_p2 == 1) return 1;
		else return 0;
	}
}

int main(){
	// Menu para 1v1 e, futuramente, 1vCOMPUTER
	char choose;

	system("clear");
	printf("Othelo | dev: Vinícius de Sá Ferreira - 15491650\n\n");
	printf("[0] Sair.\n");
	printf("[1] PLAYER VS PLAYER.\n");
	printf("Escolha: ");

	scanf(" %c", &choose);
	choose -= '0';

	switch (choose){
		case 1:
			break;

		default:
			printf("Saindo...\n");
			return 0;
	}

	system("clear");

	// Tabuleiro (grid) e posicoes das pecas dos jogadores
	char grid[8][8];
	short int sp1[8][8], sp2[8][8]; //sp1: substituicao player 1 | sp2: substituicao player 2
	short int p1[8][8], p2[8][8];
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			p1[i][j] = 0; // 0 <- sem peca nessa posicao
			p2[i][j] = 0;

			sp1[i][j] = 0;
			sp2[i][j] = 0;

			if ((i == 3 && j == 4) || (i == 4 && j == 3)) p1[i][j] = 1;
			if (i == j && (i == 3 || i == 4)) p2[i][j] = 1; // 1 <- com peca nessa posicao
		}
	}

	// Mostra o tabuleiro
	printf("  A B C D E F G H\n");
	for (int i=0; i<8; i++){
		printf("%d ", i+1);
		for (int j=0; j<8; j++){
			grid[i][j] = EMPTY;
			if (p1[i][j] > 0) grid[i][j] = 'O';
			if (p2[i][j] > 0) grid[i][j] = 'X';
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}

	// Jogada do player1
	char pos[11]; // 11 para evitar stack smashing em caso de jogada fora do tabuleiro
	short int player=1, valid=0, aux_valid=0;
	short int x,y; // Posicao no tabuleiro digitada pelo jogador
	short int fim=0; //1: player 1 (O) ganhou; 2: player 2 (X) ganhou; 3: empate

	while (1){ // While 1 para rodar ate o jogo acabar
		printf("\nDigite q! para sair.\n\n");
		printf("<PLAYER %hd>\nInsira a posicao para colocar %c (ex.: F3): ", player, (player == 1) ? ('O') : 'X');
		do {
			if ((x > 7) || (y < 0 || y > 7)) printf("Jogada fora do tabuleiro! Insira uma posicao valida: ");
			scanf(" %s", pos);

			if (pos[0] == 'q' && pos[1] == '!'){
				printf("Saindo...\n");
				return 0; // Se digitar q! sai do jogo
			}

			x = pos[1]-'0'-1;
			y = minPositivo(pos[0]-'a', pos[0]-'A');
		} while ((x > 7) || (y < 0 || y > 7));

		if (player == 1){
			//Verificacao e substituicao do player
			valid = 0; // Pressupomos que eh invalido, se for valido vai virar 1 se houver algum p1 na mesma linha, coluna ou diagonal de (x,y)
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (p1[x][y] == 1 || p2[x][y] == 1) aux_valid = 0; // Se tiver pecas na posicao eh invalido
					else if ((i != x || j != y) && (p1[i][j] == 1)){// Se tiver uma peca de p1 em (i,j), com (i,j) != (x,y)
						aux_valid = 0;
						if (i == x && abs(y-j) > 1){
							//Mesma linha
							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=min(y,j)+1; k<max(y,j); k++){
									if (t == 0){
										if (p2[x][k] == 0){
											continua = 0;
											break;
										}
									}
									else if (p2[x][k] == 1){//Se tiver algum p2
										sp1[x][k] = 1; //Coloca o p1
									}
									
								}
							}
							if (continua == 1) aux_valid = 1;

						} if (j == y && abs(x-i) > 1) {
							//Mesma coluna
							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=min(x,i)+1; k<max(x,i); k++){
									if (t == 0){
										if (p2[k][y] == 0){
											continua = 0;
											break;
										}
									}
									else if (p2[k][y] == 1){//Se tiver algum p2
										sp1[k][y] = 1; //Coloca o p1
									}
								}
							}
							if (continua == 1) aux_valid = 1;

						} if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
							//Em alguma diagonal de (x,y)
							short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
							short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=1; k<abs(x-i); k++){
									if (t == 0){
										if (p2[x+k*norm_x][y+k*norm_y] == 0){
											continua = 0;
											break;
										}
									}
									else if (p2[x+k*norm_x][y+k*norm_y] == 1){//Se tiver algum p2
										sp1[x+k*norm_x][y+k*norm_y] = 1; //Coloca o p1
									}
								}
							}
							if (continua == 1) aux_valid = 1;
						}

						if (aux_valid == 1) valid = 1;
					}
				}
			}
			//Fim verificacao e substituicao do player 1

		} else { // Se for o player 2 jogando
			//Verificacao e substituicao do player 2
			valid = 0; // Pressupomos que eh invalido, se for valido vai virar 1 pela mesma linha, coluna ou diagonal de (x,y)
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (p1[x][y] == 1 || p2[x][y] == 1) aux_valid = 0; // Se tiver pecas na posicao eh invalido
					else if ((i != x || j != y) && (p2[i][j] == 1)){// Se tiver uma peca de p2 em (i,j), com (i,j) != (x,y)
						aux_valid = 0; // Pressupomos que eh invalido, se for valido vai virar 1 se estiver na mesma linha, coluna ou diagonal
						if (i == x && abs(y-j) > 1){
							//Mesma linha
							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=min(y,j)+1; k<max(y,j); k++){
									if (t == 0){
										if (p1[x][k] == 0){
											continua = 0;
											break;
										}
									}
									else if (p1[x][k] == 1){//Se tiver algum p1
										sp2[x][k] = 1; //Coloca o p2
									}
								}
							}
							if (continua == 1) aux_valid = 1;

						} if (j == y && abs(x-i) > 1) {
							//Mesma coluna
							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=min(x,i)+1; k<max(x,i); k++){
									if (t == 0){
										if (p1[k][y] == 0){
											continua = 0;
											break;
										}
									}
									else if (p1[k][y] == 1){//Se tiver algum p1
										sp2[k][y] = 1; //Coloca o p2
									}
								}
							}
							if (continua == 1) aux_valid = 1;

						} if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
							//Em alguma diagonal de (x,y)
							short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
							short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

							int continua=1;
							for (int t=0; t<2; t++){
								if (continua == 0) break;
								for (int k=1; k<abs(x-i); k++){
									if (t == 0){
										if (p1[x+k*norm_x][y+k*norm_y] == 0){
											continua = 0;
											break;
										}
									}
									else if (p1[x+k*norm_x][y+k*norm_y] == 1){//Se tiver algum p1
										sp2[x+k*norm_x][y+k*norm_y] = 1; //Coloca o p2
									}
								}
							}
							if (continua == 1) aux_valid = 1;
						}

						if (aux_valid == 1) valid = 1;
					}
				}
			}
			//Fim verificacao e substituicao do player 2
		}

		if (valid == 1){
			if (player == 1){
				p1[x][y] = 1; //Adiciona a peca na posicao x,y do p1
				for (int i=0; i<8; i++){
					for (int j=0; j<8; j++){
						if (sp1[i][j] == 1){
							sp1[i][j] = 0;
							p1[i][j] = 1;
							p2[i][j] = 0;
						}
					}
				}
				player = 2;
			} else {
				p2[x][y] = 1; //Adiciona a peca na posicao x,y do p2
				for (int i=0; i<8; i++){
					for (int j=0; j<8; j++){
						if (sp2[i][j] == 1){
							sp2[i][j] = 0;
							p2[i][j] = 1;
							p1[i][j] = 0;
						}
					}
				}
				player = 1;
			}

			valid = 0;
		} else {
			printf("\nJogada invalida, coloque em uma posicao que cerce alguma peca do PLAYER %d por alguma outra peca sua!!!\n", (player==1) ? (2) : (1));
			system("read -p \"\" buffer"); //Pausa o programa para ver a mensagem de jogada invalida
		}

		//Atualiza o tabuleiro
		system("clear");
		printf("  A B C D E F G H\n");
		for (int i=0; i<8; i++){
			printf("%d ", i+1);
			for (int j=0; j<8; j++){
				if (p1[i][j] > 0) grid[i][j] = 'O';
				if (p2[i][j] > 0) grid[i][j] = 'X';

				printf("%c ", grid[i][j]);
			}
			printf("\n");
		}

		//Verifica se acabou
		// Caso player 1 ganhou
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				if (p2[i][j] == 0){
					fim = 1;
				} else {
					fim = -1;
					break;
				}
			}
			if (fim == -1){
				fim = 0;
				break;
			}
		}
		if (fim == 1){
			printf("\n\nPLAYER 1 GANHOU!!!\n");
			return 0;
		}

		// Caso player 2 ganhou
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				if (p1[i][j] == 0){
					fim = 2;
				} else {
					fim = -1;
					break;
				}
			}
			if (fim == -1){
				fim = 0;
				break;
			}
		}
		if (fim == 2){
			printf("\n\nPLAYER 2 GANHOU!!!\n");
			return 0;
		}

		// Caso empate por tabuleiro completo
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				if (grid[i][j] != EMPTY){
					fim = 3;
				} else {
					fim = -1;
					break;
				}
			}
			if (fim == -1){
				fim = 0;
				break;
			}
		}
		if (fim == 3){
			printf("\n\nEMPATE POR TABULEIRO COMPLETO!!!\n");
		}

		// Caso empate por afogamento
		int afog_aux = 1;
		if (fim == 3) afog_aux = 0; // Se o tabuleiro estiver completo nao ha jogada valida, mas nao eh afogamento
		else {
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (Afogou(p1, p2, i, j, player) == 0) { // Se tiver alguma jogada valida de p1 ou p2
						afog_aux = 0;
						break;
					}
				}
			}

			if (afog_aux == 1) {
				printf("\n\nEMPATE POR AFOGAMENTO!!!\n");
			}
		}

		// Contablizando pecas em caso de empate, como criterio de desempate
		if (fim == 3 || afog_aux == 1) {
			printf("CONTABILIZANDO AS PECAS PARA DESEMPATE");
			for (int i=0; i<6; i++) { // Carregamento
				system("sleep 0.5");
				printf(".");
				system("sleep 0.5");
				fflush(stdout);
			}
			printf("\n");

			int qtd_p1, qtd_p2;
			qtd_p1 = 0;
			qtd_p2 = 0;

			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (p1[i][j] == 1) qtd_p1++;
					else if (p2[i][j] == 1) qtd_p2++;
				}
			}

			if (qtd_p1 > qtd_p2) printf("\n\nPLAYER 1 GANHOU COM %d PECAS A MAIS (%d x %d)!!!\n", qtd_p1-qtd_p2, qtd_p1, qtd_p2);
			else if (qtd_p2 > qtd_p1) printf("\n\nPLAYER 2 GANHOU COM %d PECAS A MAIS (%d x %d)!!!\n", qtd_p2-qtd_p1, qtd_p1, qtd_p2);
			else printf("\n\nEMPATE NA QUANTIDADE DE PECAS!!!\n");

			return 0;
		}
	}

	return 0;
}