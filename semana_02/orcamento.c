#include <stdio.h>

int main(){
	//n: minutos total
	//P: orcamento
	//X: quantidade de diarias completas
	//Y: horas alem das diarias
	//Z: minutos alem das diarias
	int n=0,P=0,X=0,Y=0,Z=0;

	scanf("%d", &n);

	X=(n/60)/12;
	Y=(n/60);
	Y=Y - (Y>=12)*(12)*X; //Subtrai as horas das diarias se tiver pelo menos uma diaria completa
	Z=n-(X*(12*60)+Y*60); //Converte as diarias e as horas em minutos e subtrai do total
	P=1000*X + (Y)*130; //Adicional das horas alem das diarias

	printf("O orcamento eh de %d reais. O servico irah demorar %d diarias, %d horas e %d minutos.",P,X,Y,Z);

	return 0;
}
