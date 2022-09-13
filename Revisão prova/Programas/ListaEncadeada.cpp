#include <stdio.h>
#include <stdlib.h>

struct noLista{
	int idade;
	struct noLista *next;
};

void imprimirList(struct noLista *inicioLista){

	struct noLista *noAtual = inicioLista;
	
	while (noAtual != NULL){
		printf("%d ->", noAtual->idade);
		noAtual = noAtual->next;
	}
	printf("NULL");	
}

int main(){
	
	struct noLista *primeiroNoLista = NULL;	
	
	
	return 0;
}
