#include <stdio.h>
#include <stdlib.h>
#include "othelo.c"

void othelo_ai();

int main() {
    char choose;

	system("clear");
	printf("Othelo | dev: Vinícius de Sá Ferreira - 15491650\n\n");
	printf("[0] Sair.\n");
	printf("[1] PLAYER VS PLAYER.\n");
    printf("[2] PLAYER VS CPU.\n");
	printf("Escolha: ");

	scanf(" %c", &choose);
	choose -= '0';

	system("clear");

	switch (choose){
		case 1:
            othelo_pvp();
			break;

        case 2:
            othelo_ai();
            break;

		default:
			printf("Saindo...\n");
			return 0;
	}

    return 0;
}

void melhor_jogada(short int *X, short int *Y, short int p1[8][8], short int p2[8][8]) {
    int semJogada_cpu = 0;
    int x,y;
    int qtd_H, qtd_V, qtd_D, qtd_max;

    qtd_max = 0;
    for (x=0; x<8; x++){
        for (y=0; y<8; y++){
            if (p2[x][y] == 0 && p1[x][y] == 0) { // Se for um espaco vazio
                for (int i=0; i<8; i++){
                    for (int j=0; j<8; j++){
                        qtd_H = 0;
                        qtd_V = 0;
                        qtd_D = 0;

                        semJogada_cpu = 1; // Pressupomos que nao vao ter jogadas possiveis
                        if ((i != x || j != y) && (p2[i][j] == 1)){
                            if (i == x && abs(y-j) > 1){
                                //Mesma linha
                                int continua=1;

                                for (int k=min(y,j)+1; k<max(y,j); k++){
                                    if (p1[x][k] == 0){
                                        continua = 0;
                                        qtd_H = 0;
                                        break;
                                    }
                                    qtd_H++;
                                }
                                if (continua == 1) semJogada_cpu = 0;

                            } if (j == y && abs(x-i) > 1) {
                                //Mesma coluna
                                int continua=1;
                                
                                for (int k=min(x,i)+1; k<max(x,i); k++){
                                    if (p1[k][y] == 0){
                                        continua = 0;
                                        qtd_V++;
                                        break;
                                    }
                                    qtd_V++;
                                }
                                if (continua == 1) semJogada_cpu = 0;

                            } if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
                                //Em alguma diagonal de (x,y)
                                short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
                                short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

                                int continua=1;

                                for (int k=1; k<abs(x-i); k++){
                                    if (p1[x+k*norm_x][y+k*norm_y] == 0){
                                        continua = 0;
                                        qtd_D = 0;
                                        break;
                                    }
                                    qtd_D++;
                                }
                                if (continua == 1) semJogada_cpu = 0;
                            }
                        }
                        if (semJogada_cpu == 0) { // Se tiver pelo menos uma jogada possivel
                            semJogada_cpu = -1;
                            break;
                        }
                    }
                    if (semJogada_cpu == -1) { // Break recursivo
                        semJogada_cpu = 0;

                        if ((qtd_H + qtd_V + qtd_D) > qtd_max) {
                            qtd_max = qtd_H + qtd_V + qtd_D;
                            *X = x;
                            *Y = y;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void othelo_ai() {
    // Tabuleiro (grid) e posicoes das pecas dos jogadores
	char grid[8][8];
	short int sp1[8][8], sp2[8][8]; //sp1: substituicao player 1 | sp2: substituicao CPU
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
    short int x_bot, y_bot;
	short int fim=0; //1: player 1 (O) ganhou; 2: CPU (X) ganhou; 3: empate

    x_bot = -1;
    y_bot = -1;
	while (1){ // While 1 para rodar ate o jogo acabar
		if (player == 1){
            if (x_bot > -1 && y_bot > -1) printf("<CPU> JOGOU EM %c%hd!!!\n\n", y_bot, x_bot);
            printf("\nDigite q! para sair.\n\n");
            printf("<PLAYER 1>\nInsira a posicao para colocar O (ex.: F3): ");

            x = 1; // Inicializamos x de forma que nao entre no if abaixo
            y = 1; // Inicializamos y de forma que nao entre no if abaixo
            do {
                if ((x > 7) || (y < 0 || y > 7)) printf("Jogada fora do tabuleiro! Insira uma posicao valida: ");
                scanf(" %s", pos);

                if (pos[0] == 'q' && pos[1] == '!'){
                    printf("Saindo...\n");
                    return; // Se digitar q! sai do jogo
                }

                x = pos[1]-'0'-1;
                y = minPositivo(pos[0]-'a', pos[0]-'A');
            } while ((x > 7) || (y < 0 || y > 7));

			//Verificacao e substituicao do player 1
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
									else if (p2[x][k] == 1){//Se tiver algum do CPU
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
									else if (p2[k][y] == 1){//Se tiver algum do CPU
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
									else if (p2[x+k*norm_x][y+k*norm_y] == 1){//Se tiver algum do CPU
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

		} else { // Se for o CPU jogando
			//Verificacao e substituicao do CPU
            valid = 1; // Vai ser valido porque a funcao melhor_jogada verifica continuidade

            melhor_jogada(&x,&y,p1,p2);
            x_bot = x+1; // linha
            y_bot = y+'A'; // coluna

			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (p1[x][y] == 1 || p2[x][y] == 1) aux_valid = 0; // Se tiver pecas na posicao eh invalido
					else if ((i != x || j != y) && (p2[i][j] == 1)){// Se tiver uma peca do CPU em (i,j), com (i,j) != (x,y)
						if (i == x && abs(y-j) > 1){
							//Mesma linha
                            for (int k=min(y,j)+1; k<max(y,j); k++){
                                if (p1[x][k] == 1){//Se tiver algum p1
                                    sp2[x][k] = 1; //Coloca o do CPU
                                }
                            }

						} if (j == y && abs(x-i) > 1) {
							//Mesma coluna
                            for (int k=min(x,i)+1; k<max(x,i); k++){
                                if (p1[k][y] == 1){//Se tiver algum p1
                                    sp2[k][y] = 1; //Coloca o do CPU
                                }
                            }

						} if (abs(x-i) == abs(y-j) && abs(x-i) > 1) {
							//Em alguma diagonal de (x,y)
							short int norm_x = abs(x-i)/(i-x); //Versor unitario em x
							short int norm_y = abs(y-j)/(j-y); //Versor unitario em y

                            for (int k=1; k<abs(x-i); k++){
                                if (p1[x+k*norm_x][y+k*norm_y] == 1){//Se tiver algum p1
                                    sp2[x+k*norm_x][y+k*norm_y] = 1; //Coloca o do CPU
                                }
                            }

						}
					}
				}
			}
			//Fim verificacao e substituicao do CPU
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
				p2[x][y] = 1; //Adiciona a peca na posicao x,y do CPU
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
			printf("\nJogada invalida, coloque em uma posicao que cerce alguma peca do %s por alguma outra peca sua!!!\n", (player==1) ? ("CPU") : ("PLAYER 1"));
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

        if (player == 2) {
            printf("\nAperte ENTER para que o CPU efetue sua jogada.");
            printf("\n");
            system("read -p \"\" buffer"); //Pausa o programa para ver as substituicoes do player 1 antes de mostrar as do CPU
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
			return;
		}

		// Caso CPU ganhou
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
			printf("\n\nCPU GANHOU!!!\n");
			return;
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
			else if (qtd_p2 > qtd_p1) printf("\n\nCPU GANHOU COM %d PECAS A MAIS (%d x %d)!!!\n", qtd_p2-qtd_p1, qtd_p1, qtd_p2);
			else printf("\n\nEMPATE NA QUANTIDADE DE PECAS!!!\n");

			return;
		}
	}

    return;
}