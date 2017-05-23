#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N_FILA 5 
int x =  1;

void verde(){
	x = x+1;
	return x;
}

void vermelho(){
	x = x-1;
	return x;
}

void verificaCaixa(void * x){
	if(x == 0){
		printf("Caixa ocupado!");
		atendendo();
	} else if(x == 1){
		printf("Caixa Livre!");
		fila();
	}
	return x;
}
void * fila(void * x){
	while(1){
		if(N_FILA > 5){
			printf("fila está lotada!");
			cliente();
		} else{
			
		}
	}
}

void * atendendo(void * x){
	while(1){
		printf("Caixa atendeu um cliente. \n");
		verde();
	}
	return x;
}

void * cliente(void * v){
	int id = * (int *) x;
	if(N_FILA ){
		printf ("Cliente %d entrou na loja. \n");

		printf("Cliente %d entrou na fila");

		printf("Cliente %d deixou a loja.\n");
	}
	else{
		printf("Loja está lotada, cliente %d não entrou na loja.\n");
		return x;
	}
int main (){
	for(i = 0; i < N_FILA; i++){

	}

	for(i = 0; i < N_FILA; i++){

	}
	return 0;
}
