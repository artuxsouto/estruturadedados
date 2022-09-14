#include <stdio.h>
#include <stdlib.h>

struct noPilha{
	struct noPilha *noAnterior;
	int idade;
	int sexo;
	struct noPilha *proximoNo;	
};

struct noPilha *empilhar(struct noPilha *inicioPilha, int idade, int sexo){
	struct noPilha *novoNo = (struct noPilha*)malloc(sizeof(struct noPilha));
	
	novoNo->noAnterior = NULL;
	novoNo->idade = idade;
	novoNo->sexo = sexo;
	novoNo->proximoNo = inicioPilha;
	
	if (inicioPilha != NULL)
		inicioPilha->noAnterior = novoNo;
		
	return novoNo;
}

struct noPilha *desempilhar(struct noPilha *topoPilha){
	struct noPilha *percorrePilha = topoPilha;
	
	if (percorrePilha == NULL){
		return topoPilha;
	}
	topoPilha = percorrePilha->proximoNo;
	topoPilha->noAnterior = NULL;
	
	free(percorrePilha);
	
	return topoPilha;
}

void imprimirPilha(struct noPilha *topoPilha){
	struct noPilha *noAtual = topoPilha;
	
	while (noAtual != NULL){
		printf("\n %d ", noAtual->idade);
		noAtual = noAtual->proximoNo;
	}
	printf("\n NULL");
}

int main(){
	
	struct noPilha *topoPilha = NULL;
	
	printf("Programa exercicio 2 em execucao!\n");
	
	int idade;
	int sexo;
	
	for (int i = 0; i < 5; i++){
		
		printf("\nDigite a idade: ");
		scanf("%d", &idade);
		
		printf("\nDigite o sexo(1-M, 2-F): ");
		scanf("%d", &sexo);
		
		topoPilha = empilhar(topoPilha, idade, sexo);
	}
	
	printf("\n\n Elementos da pilha \n");
	imprimirPilha(topoPilha);
	
	while (topoPilha != NULL){
		if ( topoPilha->sexo == 2){
			printf("\nIdade: %d", topoPilha->idade);
			printf("\nSexo: Feminino");
		}
		topoPilha = desempilhar(topoPilha);
	}
}
