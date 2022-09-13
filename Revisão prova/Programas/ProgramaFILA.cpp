#include <stdlib.h>
#include <stdio.h>

struct noFila{
	struct noFila *noAnterior;
	int n;
	struct noFila *proximoNo;
};

struct noFila *inserirFila(struct noFila *inicioFila, int nvNumero){
	struct noFila *percorreFila = inicioFila;
	struct noFila *novoNo =(struct noFila*)malloc(sizeof(struct noFila));
	
	if (percorreFila != NULL){
		while (percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = novoNo;
	}
	novoNo->noAnterior = percorreFila;
	novoNo->n = nvNumero;
	novoNo->proximoNo = NULL;
	
	if (inicioFila == NULL){
		return novoNo;
	}else{
		return inicioFila;
	}
	
}

struct noFila *imprimirFila(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;
	
	while(noAtual != NULL){
		printf("%d -> ", noAtual->n);
		noAtual = noAtual->proximoNo;
	}
	printf("NULL");
}

struct noFila *removerNumero(struct noFila *inicioFila){
	struct noFila *percorreFila = inicioFila;
	
	if (percorreFila == NULL){
		return inicioFila;
	}
	inicioFila = percorreFila->proximoNo;
	inicioFila->noAnterior = NULL;
	
	free(percorreFila);
	
	return inicioFila;
}

int  contarElementos(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;
	int contador = 0;
	
	while (noAtual != NULL){
		contador++;
		noAtual = noAtual->proximoNo;
	}
	return contador;
}

int main(){
	
	struct noFila *inicioFila = NULL;
	int p;
	
	printf("Programa para inserir 5 numeros\n");
	
	for (int i = 0; i < 5; i++){
		printf("Digite o numero %d: ", i + 1);
		scanf("%d", &p);
		
		inicioFila = inserirFila(inicioFila, p);		
	}
	
	printf("\nLista Abaixo\n");
	
	imprimirFila(inicioFila);
	
	int qtd = contarElementos(inicioFila);
	printf("\nQuantidade de elementos na fila %d", qtd);
	
	printf("\nRemovendo 2 Elementos\n");
	
	inicioFila = removerNumero(inicioFila);
	imprimirFila(inicioFila);
	
	inicioFila = removerNumero(inicioFila);
	imprimirFila(inicioFila);
		
	return 0;
}
