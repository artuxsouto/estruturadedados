#include <stdio.h>
#include <stdlib.h>

struct noFila{
    struct noFila *noAnterior;
    int codigo;
    int totalDeVagas;
    int candidatosM;
    int candidatosF;
    struct noFila *proximoNo;
};

struct noFila *inserirFila(struct noFila *inicioFila, int codigo, int totalDeVagas, int candidatosM, int candidatosF){
    struct noFila *percorreFila = inicioFila;
    struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));

    if(percorreFila != NULL){
        while (percorreFila->proximoNo != NULL){
            percorreFila = percorreFila->proximoNo;
        }
        percorreFila->proximoNo = novoNo;
    }
    novoNo->noAnterior = percorreFila;
    novoNo->codigo = codigo;
    novoNo->totalDeVagas = totalDeVagas;
    novoNo->candidatosM = candidatosM;
    novoNo->candidatosF = candidatosF;
    novoNo->proximoNo = NULL;

    if (inicioFila == NULL){
        return novoNo;
    }else{
        return inicioFila;
    }
}

void imprimirFila(struct noFila *inicioFila){
    struct noFila *noAtual = inicioFila;

    while(noAtual != NULL){
        printf("\nCodigo do curso: %d\nNumero de vagas: %d\nCandidatos M: %d\nCandidatos F: %d\n", noAtual->codigo, noAtual->totalDeVagas, noAtual->candidatosM, noAtual->candidatosF);
        noAtual = noAtual->proximoNo;
    }
    printf("\nNULL");
}

struct noFila *buscarElemento(struct noFila *inicioFila, int elemento){
    struct noFila *percorreFila = inicioFila;

    while(percorreFila != NULL){
        if(percorreFila->codigo == elemento){
            return percorreFila;
        }else{
            percorreFila = percorreFila->proximoNo;
        }
        return NULL;
    }
}

int main(){
    
    struct noFila *inicioFila = NULL;

    printf("\n*** Exercicio 5 em execucao ***");
    
    int codigo;
    int totalDeVagas;
    int candidatosM;
    int candidatosF;

    for (int i = 0; i < 2; i++){
        printf("\nDigite o codigo do curso %d: ", i + 1);
        scanf("%d", &codigo);

        printf("\nDigite o total de vagas: ");
        scanf("%d", &totalDeVagas);

        printf("\nDigite a quantidade de candidatos do sexo M: ");
        scanf("%d", &candidatosM);

        printf("\nDigite a quantidade de candidatos do sexo F: ");
        scanf("%d", &candidatosF);

        printf("\nCandidatos por vaga: %d\n\n", (candidatosM + candidatosF) / totalDeVagas);

        inicioFila = inserirFila(inicioFila, codigo, totalDeVagas, candidatosM, candidatosF);
    }
    printf("\nMostrar Fila:\n");
    imprimirFila(inicioFila);

    int buscar;

    printf("\n\n*** Buscar curso por codigo ***\n\n");
    printf("Digite o codigo pra busca: ");
    scanf("%d", &buscar);

    if(buscarElemento(inicioFila, buscar) == NULL){
        printf("\nCURSO INEXISTENTE");
    }else{
        printf("\nCurso encontrado:\n\nNumero de vagas: %d\nCandidatos por vagas: %d", inicioFila->totalDeVagas, (inicioFila->candidatosM + inicioFila->candidatosM) / inicioFila->totalDeVagas);
    }
    return 0;
}