#include <stdio.h>
#include <stdlib.h>

struct noFila{
	struct noFila *noAnterior;
	int codigo;
	int idade;
	float salario;
	struct noFila *proximoNo;
};

struct noFila *inserirFila(struct noFila *inicioDaFila, int codigo, int idade, float salario){
	struct noFila *percorreFila = inicioDaFila;
	struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));
	
	if (percorreFila != NULL){
		while (percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = novoNo;
	}
	
	novoNo->noAnterior = percorreFila;
	novoNo->codigo = codigo;
	novoNo->idade = idade;
	novoNo->salario = salario;
	novoNo->proximoNo = NULL;
	
	if(inicioDaFila == NULL){
		return novoNo;
	}else{
		return inicioDaFila;
	}
}

void imprimirRelatorio(struct noFila *inicioDaFila){
	struct noFila *noAtual = inicioDaFila;
	
	while(noAtual != NULL){
		printf("\nCodigo do cliente: %d\nIdade: %d\nSalario: %.2f", noAtual->codigo, noAtual->idade, noAtual->salario);
		noAtual = noAtual->proximoNo;
	}
	printf("\n\n-- FIM --");
}

void imprimirFila(struct noFila *inicioDaFila){
	struct noFila *noAtual = inicioDaFila;
	int contador = 0;
	
	while (noAtual != NULL){
		if(contador == 0){
			contador = 1;
			printf("\nO cliente codigo %d e o primeiro da fila\nEm seguida: ", noAtual->codigo);
			noAtual = noAtual->proximoNo;
		}
		printf("codigo do cliente: %d\n", noAtual->codigo);
		noAtual = noAtual->proximoNo;
	}
}

int main(){
	
	struct noFila *inicioDaFila = NULL;
	int codigo;
	int idade;
	float salario;
	
	for(int i = 0; i < 5; i++){
		printf("\nDigite o codigo do cliente %d: ", i + 1);
		scanf("%d", &codigo);
		
		printf("\nDigite a idade do cliente: ");
		scanf("%d", &idade);
		
		printf("\nDigite o salario do cliente: \n");
		scanf("%f", &salario);
		
		inicioDaFila = inserirFila(inicioDaFila, codigo, idade, salario);
	}
	
	printf("\nRelatorio:\n");
	imprimirRelatorio(inicioDaFila);
	printf("\n\nOrdem da fila\n");
	imprimirFila(inicioDaFila);
	
	return 0;
}
