#include <stdio.h>
#include <stdlib.h>

struct noLista{
	struct noLista *noAnterior;
	int idade;
	struct noLista *proximoNo;
};

struct noLista *inserirNoInicio(struct noLista *inicioDaLista, int novoNumero){
	struct noLista *novoNo = (struct noLista*)malloc(sizeof(struct noLista));
	
	novoNo->noAnterior = NULL;
	novoNo->idade = novoNumero;
	novoNo->proximoNo = inicioDaLista;
	
	if (inicioDaLista != NULL){
		inicioDaLista->noAnterior = novoNo;
	}
	return novoNo;	
}

void imprimirLista(struct noLista *inicioDaLista){
	
	struct noLista *noAtual = inicioDaLista;
	
	while (noAtual != NULL){
		printf("%d->",noAtual->idade);
		noAtual = noAtual->proximoNo;
	}
	printf("NULL");
}

struct noLista *inserirNoFinal(struct noLista *inicioDaLista, int novoNumero){
	struct noLista *percorreLista = inicioDaLista;
	struct noLista *novoNo = (struct noLista*)malloc(sizeof(struct noLista));
	
	if (percorreLista != NULL){
		while (percorreLista->proximoNo != NULL){
			percorreLista = percorreLista->proximoNo;
		}
		percorreLista->proximoNo = novoNo;
	}
	novoNo->noAnterior = percorreLista;	
	novoNo->idade = novoNumero;
	novoNo->proximoNo = NULL;
	
	if (inicioDaLista == NULL){
		return novoNo;
	}else{
		return inicioDaLista;
	}
}

struct noLista *removerIdade(struct noLista *inicioDaLista, int idadePraRemover){
	struct noLista *percorreLista = inicioDaLista;
	
		while (percorreLista != NULL && percorreLista->idade != idadePraRemover){
			percorreLista = percorreLista->proximoNo;
		}
		if (percorreLista == NULL){
			return inicioDaLista;
		}
		if (percorreLista->noAnterior == NULL){
			inicioDaLista = percorreLista->proximoNo;
		}else{
			percorreLista->noAnterior->proximoNo = percorreLista->proximoNo;
		}
		if (percorreLista->proximoNo != NULL){
			percorreLista->proximoNo->noAnterior = percorreLista->noAnterior;
		}
		free(percorreLista);
		
		return inicioDaLista;
}

struct noLista *buscarNoLista(struct noLista *inicioLista, int idadeProcurada){
	struct noLista *percorreLista;
	percorreLista = inicioLista;
	
	while (percorreLista != NULL)
	{	
		if (percorreLista->idade == idadeProcurada)
		{
		  	
		    return percorreLista;
		}
		else
		{
		  percorreLista = percorreLista->proximoNo;
     	}
     }
	return NULL;
}

int main(){
	
	struct noLista *primeiroNoDaLista = NULL;
	int numero;
	
	printf("Olá! Program2 em execução.\n");
	
	for (int i = 0; i < 2; i++){
		printf("\nDigite uma idade: ");
		scanf("%d", &numero);
		
		primeiroNoDaLista = inserirNoInicio(primeiroNoDaLista, numero);
	}
	
	for (int j = 0; j < 2; j++){
		printf("\nDigite uma idade que vai pro final: ");
		scanf("%d", &numero);
		
		primeiroNoDaLista = inserirNoFinal(primeiroNoDaLista, numero);
	}
	
	imprimirLista(primeiroNoDaLista);
	
	printf("\nDigite uma idade pra ser removida: ");
	scanf("%d", &numero);
	primeiroNoDaLista = removerIdade(primeiroNoDaLista, numero);
	
	imprimirLista(primeiroNoDaLista);
	
	printf("\nDigite uma idade pra ser buscada: ");
	scanf("%d", &numero);
	
	if (buscarNoLista(primeiroNoDaLista, numero) == NULL){
		printf("\nIdade não encontrada.");
	}else{
		printf("\nIdade encontrada.");
	}	
		
	return 0;
}
