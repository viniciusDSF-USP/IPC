#include <stdio.h>

int main(){
	//prec_tor: preco da tortilla em pesos mexicanos;
	//prec_tej: preco do tejuine em pesos mexicanos;
	//prec_man: preco do manzapane em pesos mexicanos;
	//pesos: quantidade de pesos mexicanos que dikson tem.

	float prec_tort, prec_tej, prec_man, pesos;

	scanf("%f %f %f %f", &prec_tort, &prec_tej, &prec_man, &pesos);

	if (prec_tort+prec_tej+prec_man <= pesos){
		printf("Dikson pode comprar tortilla, tejuine e manzapane");
	} else if (prec_tort+prec_tej <= pesos){
		printf("Dikson pode comprar tortilla e tejuine");
	} else if (prec_tort <= pesos) {
		printf("Dikson pode comprar tortilla");
	} else {
		printf("Dikson nao pode comprar nada");
	}

	return 0;
}
