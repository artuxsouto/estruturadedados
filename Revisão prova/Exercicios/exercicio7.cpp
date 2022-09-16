#include <stdlib.h>
#include <iostream>

using namespace std;

struct noFila
{
    struct noFila *noAnterior;
    float peso;
    float altura;
    struct noFila *proximoNo;
};

struct noFila *inserirFila(struct noFila *inicioFila, float peso, float altura){
    struct noFila *percorreFila = inicioFila;
    struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));

    if (percorreFila != NULL){
        while (percorreFila->proximoNo != NULL){
            percorreFila = percorreFila->proximoNo;
        }
        percorreFila->proximoNo = novoNo;
    }
    novoNo->noAnterior = percorreFila;
    novoNo->peso = peso;
    novoNo->altura = altura;
    novoNo->proximoNo = NULL;

    if (inicioFila == NULL){
        return novoNo;
    }else{
        return inicioFila;
    }
}

void imprimirFila(struct noFila *inicioFila){
    struct noFila *noAtual = inicioFila;

    while (noAtual != NULL){
        cout << "Peso: " << noAtual->peso << " Altura: " << noAtual->altura << endl;
        noAtual = noAtual->proximoNo;
    }
    cout << "\nNULL\n\n";
}

struct noFila *removerFila(struct noFila *inicioFila){
    struct noFila *percorreFila = inicioFila;

    if (percorreFila == NULL){
        return inicioFila;
    }

    inicioFila = percorreFila->proximoNo;
    if (inicioFila == NULL)
    inicioFila->noAnterior = NULL;
    free(percorreFila);

    return inicioFila;
}

int main(){

    struct noFila *inicioFila = NULL;
    float peso;
    float altura;
    float imc;

    for (int i = 0; i < 5; i++){
        cin >> peso >> altura;
        inicioFila = inserirFila(inicioFila, peso, altura);
    }

    cout << "\n\n*** Fila Atual ***\n\n";
    imprimirFila(inicioFila);

    while (inicioFila != NULL){
        imc = inicioFila->peso / (inicioFila->altura * inicioFila->altura);
        if(imc > 18.5 && imc < 25){
            cout << "Peso Ideal\n";
            inicioFila = inicioFila->proximoNo;
        }else if(imc < 18.5){
            cout << "Voce esta abaixo do peso ideal!\n";
            inicioFila = inicioFila->proximoNo;
        }else{
            cout << "Voce esta acima do peso ideal!\n";
            inicioFila = inicioFila->proximoNo;
        }
    }

    return 0;
}