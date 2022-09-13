#include <stdio.h>
#include <stdlib.h>

struct noLista{
	int idade;
	struct noLista *next;
};

void imprimirList(struct noLista *inicioLista){

	struct noLista *noAtual = inicioLista;
	
	while (noAtual != NULL){
		printf("%d -> ", noAtual->idade);
		noAtual = noAtual->next;
	}
	printf("NULL");	
}

struct noLista *inserirNoLista(struct noLista *inicioLista, int n){
	
	struct noLista *novoNo = (struct noLista*) malloc(sizeof(struct noLista));
	
	novoNo-> idade = n;
	
	novoNo-> next = inicioLista;
	
	return novoNo;
}

struct noLista *inserirFinalLista(struct noLista *inicioLista, int novoNumero){
	
	struct noLista *percorreLista = inicioLista;
	
	struct noLista *novoNo = (struct noLista*)malloc(sizeof(struct noLista));
	
	while(percorreLista->next != NULL){
		percorreLista = percorreLista->next;
	}
	
	novoNo->idade = novoNumero;
	novoNo->next = percorreLista->next;
	percorreLista->next = novoNo;
	
	return inicioLista;
}

struct noLista *removeNoLista(struct noLista *inicioLista, int elementoDesejado){
	
	struct noLista *noAnterior = NULL;
	struct noLista *percorreLista = inicioLista;
	
	while (percorreLista != NULL && percorreLista->idade != elementoDesejado){
		noAnterior = percorreLista;
		percorreLista = percorreLista->next;
	}
	if (percorreLista == NULL){
		return inicioLista;
	}
	if (noAnterior == NULL){
		inicioLista = percorreLista->next;
	}else{
		noAnterior->next = percorreLista->next;
	}
	free(percorreLista);
	
	return inicioLista;
}

struct noLista *buscarNoLista(struct noLista *inicioLista, int elementoDesejado){
	struct noLista *percorreLista;
	percorreLista = inicioLista;
	
	while (percorreLista != NULL)
	{
			
	
		if (percorreLista->idade == elementoDesejado)
		{
		  	
		    return percorreLista;
		}
		else
		{
		  percorreLista = percorreLista->next;
     	}
     }
	return NULL;
}

struct noLista *inserirXPosicao(struct noLista *inicioLista, int novoNumero, int posicaoDesejada){
	int contador = 0;
	struct noLista *percorreLista = inicioLista;
	struct noLista *novoNo = (struct noLista*)malloc(sizeof(struct noLista));
	
	while ((contador < posicaoDesejada) && (percorreLista->next != NULL)){
		percorreLista = percorreLista->next;
		contador++;		
	}
	novoNo->idade = novoNumero;
	novoNo->next = percorreLista->next;
	percorreLista->next = novoNo;
	
	return inicioLista;
}
	

int main(){
	
	struct noLista *primeiroNoLista = NULL;
	
	primeiroNoLista = inserirNoLista(primeiroNoLista, 10);
	
	primeiroNoLista = inserirNoLista(primeiroNoLista, 15);
	
	primeiroNoLista = inserirNoLista(primeiroNoLista, 22);
	
	primeiroNoLista = inserirNoLista(primeiroNoLista, 28);
	
	primeiroNoLista = inserirNoLista(primeiroNoLista, 18);
	
	primeiroNoLista = inserirFinalLista(primeiroNoLista, 42);
	
	primeiroNoLista = inserirFinalLista(primeiroNoLista, 25);
	
	primeiroNoLista = removeNoLista(primeiroNoLista, 10);
	

	
	primeiroNoLista = inserirXPosicao(primeiroNoLista, 30, 1);
	
	
	imprimirList(primeiroNoLista);
	
	if( buscarNoLista(primeiroNoLista, 30) == NULL)
	 {
	     printf("não  na lista");
	     
	 }
	else  {
	        printf(" esta na lista");
	    }
		
	return 0;
}
