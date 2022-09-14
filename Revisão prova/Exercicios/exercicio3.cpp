#include <stdio.h>
#include <stdlib.h>

struct noPilha{
	struct noPilha *noAnterior;
	int n;
	struct noPilha *proximoNo;
};

struct noPilha *empilhar(struct noPilha *inicioPilha, int numero){
	struct noPilha *novoNo = (struct noPilha*)malloc(sizeof(struct noPilha));
	
	novoNo->noAnterior = NULL;
	novoNo->n = numero;
	novoNo->proximoNo = inicioPilha;
	
	if(inicioPilha != NULL){
		inicioPilha->noAnterior = novoNo;
	}
	return novoNo;
}

struct noPilha *desempilhar(struct noPilha *topoPilha){
	struct noPilha *percorrePilha = topoPilha;
	
	if (percorrePilha == NULL){
		return topoPilha;
	}
	
	topoPilha = percorrePilha->proximoNo;

	if (topoPilha != NULL)
	topoPilha->noAnterior = NULL;
	
	free(percorrePilha);
	
	return topoPilha;
}

void imprimirPilha(struct noPilha *topoPilha){
	struct noPilha *noAtual = topoPilha;
	
	if (noAtual == NULL){
		printf("Pilha Vazia!");
	}
	
	while (noAtual != NULL){
		printf("\n %d ", noAtual->n);
		noAtual = noAtual->proximoNo;
	}
}

int contarElementos(struct noPilha *topoPilha){
	struct noPilha *noAtual = topoPilha;
	int contador = 0;
	
	while (noAtual != NULL){
		contador++;
		noAtual = noAtual->proximoNo;
	}
	return contador;
}

int main(){
	
	struct noPilha *topoPilha = NULL;
	printf("Exercicio 3 em execucao!\n");
	
	int numero;
	
	for(int i = 0; i < 5; i++){
		printf("\nDigite um numero: ");
		scanf("%d", &numero);
		
		if (numero % 2 == 0){
			topoPilha = empilhar(topoPilha, numero);	
		}
	}
	
	int qtd = contarElementos(topoPilha);
	printf("\nQuantidade de elementos na pilha: %d\n", qtd);

	printf("\n***Removendo elementos da Pilha***\n");
	
	for (int j = 0; j < qtd; j++){
		topoPilha = desempilhar(topoPilha);
	}
		
	imprimirPilha(topoPilha);	
	
	return 0;
}