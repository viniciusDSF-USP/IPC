#include <stdio.h>
#include <stdlib.h>

#define EMPTY	'*'

int min(short int a, int b){
	if (a < b) return a;
	else return b;
}

int max(short int a, int b){
	if (a > b) return a;
	else return b;
}

int main(){
	// Menu para 1v1 e, futuramente, 1vCOMPUTER
	char choose;

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
	char pos[2];
	short int player=1, valid=0;
	short int x,y; // Posicao no tabuleiro digitada pelo jogador
	short int fim=0; //1: player 1 (O) ganhou; 2: player 2 (X) ganhou; 3: empate

	while (1){ // While 1 para rodar ate o jogo acabar
		printf("\nDigite q! para sair.\n\n");
		printf("<PLAYER %hd>\nInsira a posicao para colocar %c (ex.: F3): ", player, (player == 1) ? ('O') : 'X');
		scanf(" %s", pos);

		if (pos[0] == 'q' && pos[1] == '!'){
			printf("Saindo...\n");
			return 0; // Se digitar q! sai do jogo
		}

		x = pos[1]-'0'-1;
		y = pos[0]-'A';

		if (player == 1){
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (valid == 1) break; // break recursvio para quebrar os dois loops for
					if (p2[i][j] == 1 && p1[i][j] == 0){// Itera pecas do p2 e vazios do p1
						// Verifica se (x,y) esta dentro do grid 3x3 que envolve qualquer peca do p2, e tambem nao tenha nenhuma peca em (x,y)
						if ((x >= i-1 && x <= i+1) && (y >= j-1 && y <= j+1) && (p1[x][y] == 0 && p2[x][y] == 0)){
							valid = 1;

							//Substituicao
							for (int i2=0; i2<8; i2++){
								for (int j2=0; j2<8; j2++){
									if ((i2 != x || j2 != y) && (p1[i2][j2] == 1)){// Se tiver uma peca de p1 em (i2,j2) e (i2,j2) != (x,y)
										if (i2 == x){
											//Mesma linha
											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=min(y,j2)+1; k<max(y,j2); k++){
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

										} if (j2 == y) {
											//Mesma coluna
											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=min(x,i2)+1; k<max(x,i2); k++){
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

										} if (abs(x-i2) == abs(y-j2) && abs(x-i2) > 1) {
											//Em alguma diagonal de (x,y)
											short int norm_x = abs(x-i2)/(i2-x); //Versor unitario em x
											short int norm_y = abs(y-j2)/(j2-y); //Versor unitario em y

											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=1; k<abs(x-i2); k++){
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
										}
									}
								}
							}
							//Fim substituicao

							break;
						}
					}
				}
			}
		} else { // Se for o player 2 jogando
			for (int j=0; j<8; j++){
				if (valid == 1) break; // break recursivo para quebrar os dois loops for
				for (int i=0; i<8; i++){
					if (p1[i][j] == 1 && p2[i][j] == 0){// Itera pecas do p1 e vazios do p2
						// Verifica se (x,y) esta dentro do grid 3x3 que envolve qualquer peca do p1, e tambem nao tenha nenhuma peca em (x,y)
						if ((x >= i-1 && x <= i+1) && (y >= j-1 && y <= j+1) && (p1[x][y] == 0 && p2[x][y] == 0)){
							valid = 1;

							//Substituicao
							for (int i2=0; i2<8; i2++){
								for (int j2=0; j2<8; j2++){
									if ((i2 != x || j2 != y) && (p2[i2][j2] == 1)){// Se tiver uma peca de p2 em (i2,j2) e (i2,j2) != (x,y)
										if (i2 == x){
											//Mesma linha
											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=min(y,j2)+1; k<max(y,j2); k++){
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

										} if (j2 == y) {
											//Mesma coluna
											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=min(x,i2)+1; k<max(x,i2); k++){
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

										} if (abs(x-i2) == abs(y-j2) && abs(x-i2) > 1) {
											//Em alguma diagonal de (x,y)
											short int norm_x = abs(x-i2)/(i2-x); //Versor unitario em x
											short int norm_y = abs(y-j2)/(j2-y); //Versor unitario em y

											int continua=1;
											for (int t=0; t<2; t++){
												if (continua == 0) break;
												for (int k=1; k<abs(x-i2); k++){
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
										}
									}
								}
							}
							//Fim substituicao

							break;
						}
					}
				}
			}
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
			printf("\nJogada invalida, coloque em uma posicao concatenada a alguma peca do PLAYER %d!!!\n", (player==1) ? (2) : (1));
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
			if (fim == -1){
				fim = 0;
				break;
			}
			for (int j=0; j<8; j++){
				if (p2[i][j] == 0){
					fim = 1;
				} else {
					fim = -1;
					break;
				}
			}
		}
		if (fim == 1){
			printf("\n\nPLAYER 1 GANHOU!!!\n");
			return 0;
		}

		// Caso player 2 ganhou
		for (int i=0; i<8; i++){
			if (fim == -1){
				fim = 0;
				break;
			}
			for (int j=0; j<8; j++){
				if (p1[i][j] == 0){
					fim = 2;
				} else {
					fim = -1;
					break;
				}
			}
		}
		if (fim == 2){
			printf("\n\nPLAYER 2 GANHOU!!!\n");
			return 0;
		}

		// Caso empate
		for (int i=0; i<8; i++){
			if (fim == -1){
				fim = 0;
				break;
			}
			for (int j=0; j<8; j++){
				if (grid[i][j] != EMPTY){
					fim = 3;
				} else {
					fim = -1;
					break;
				}
			}
		}
		if (fim == 3){
			printf("\n\nEMPATE!!!\n");
			return 0;
		}
	}
}
