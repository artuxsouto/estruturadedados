#include <stdio.h>
#include <stdlib.h>

struct noLista{
	int n;
	struct noLista *proximoNo;
};

struct noLista *inserirInfo(struct noLista *inicioLista, int numero){
	
	struct noLista *percorreLista = inicioLista;
	struct noLista *novoNo = (struct noLista *)malloc(sizeof(struct noLista));
	
	if(percorreLista != NULL){
		while(percorreLista->proximoNo != NULL){
			percorreLista = percorreLista->proximoNo;
		}
		percorreLista->proximoNo = novoNo;
	}
	novoNo->proximoNo = NULL;
	novoNo->n = numero;
	
	if (inicioLista == NULL){
		return novoNo;		
	}else{
		return inicioLista;
	}
}

void imprimirListaInicioFim(struct noLista *inicioLista){
	struct noLista *noAtual = inicioLista;
     printf("\n Primeiro da lista e %d ", noAtual->n);
	while (noAtual->proximoNo != NULL){
	
		noAtual = noAtual->proximoNo;
	}
	
	printf("\n Ultimo da lista e %d \n", noAtual->n);
}

int contarElementos(struct noLista *inicioDaLista){
	struct noLista *noAtual = inicioDaLista;
	int contador = 0;
	
	while (noAtual != NULL){
		contador++;
		noAtual = noAtual->proximoNo;
	}
	return contador;
}

struct noLista *imprimirLista(struct noLista *inicioDaLista){
	struct noLista *noAtual = inicioLista;
	
	while (noAtual != NULL){
		printf(" %d ->", noAtual->n);
		noAtual = noAtual->proximoNo;
	}
	printf(" NULL");
}

int main(){
	
	struct noLista *inicioDaLista = NULL;
	int dado;
	
	printf("Programa exercicio 1 em execucao!\n");
	
	for (int i = 0; i < 4; i++){
		printf("Digite o numero %d: ", i+ 1);
		scanf("%d", &dado);
		
		inicioDaLista = inserirInfo(inicioDaLista, dado);
	}
	
	imprimirListaInicioFim(inicioDaLista);	
	inicioDaLista = imprimirLista(inicioDaLista);
	int qtd = contarElementos(inicioDaLista);
	
	return 0;
}
