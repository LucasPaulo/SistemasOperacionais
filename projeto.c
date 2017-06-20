#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N_CLIENTES 10	
	
int sema = 0;
	
int verde(void* argument){
	sema=1;
}

int vermelho(void * argument){
	sema=0;
	}


void* caixaOcupado(void* args){
while(sema!=0){
	int ct = *(int*)args;
	printf("Caixa atendendo",ct);
	vermelho(&sema);
	
}
}
	
void* caixaLivre(void* args){
while (sema!=1){
	int ct = *(int*)args;
	printf("caixa vazio \n",ct);
	verde(&sema);
}
}

int main(){

pthread_t threadClientes[N_CLIENTES];

int i;

int clientes[N_CLIENTES]; /*Identificador do cliente*/
	for(i=0; i < N_CLIENTES;i++){
	clientes[i] = i;
	pthread_create(&threadClientes[i],NULL,caixaLivre,(void *) &clientes[i]);
}

for(i=0; i < N_CLIENTES;i++){
	clientes[i] = i;
	pthread_create(&threadClientes[i],NULL,caixaOcupado,(void *) &clientes[i]);
}
for(i=0;i < N_CLIENTES;i++){
	pthread_join(threadClientes[i],NULL);
}
	return 0;
}
