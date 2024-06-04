#include <stdio.h>

#define gsizex 20
#define gsizey 10

int main(){
	char grid[gsizey][gsizex];
	int x,y;

	for (int i=0; i<gsizey; i++){
		x = i;
		y = x*x;

		for (int j=0; j<gsizex; j++){
			grid[i][j] = '.';
		}

		if (y <= gsizex) grid[x][y] = '*';
	}

	for (int i=0; i<gsizey; i++){
		for (int j=0; j<gsizex; j++){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}
