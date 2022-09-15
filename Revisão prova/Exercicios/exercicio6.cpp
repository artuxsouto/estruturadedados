#include <iostream>
#include <stdlib.h>
using namespace std;

struct noPilha{
    struct noPilha *noAnterior;
    int idade;
    float altura;
    struct noPilha *proximoNo;
};

struct noPilha *empilhar(struct noPilha *inicioPilha, float altura, int idade){
    struct noPilha *novoNo = (struct noPilha*)malloc(sizeof(struct noPilha));

    novoNo->noAnterior = NULL;
    novoNo->altura = altura;
    novoNo->idade = idade;
    novoNo->proximoNo = inicioPilha;

    if (inicioPilha != NULL){
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
    topoPilha->noAnterior = NULL;
    free(percorrePilha);

    return topoPilha;
}

void imprimirPilha(struct noPilha *topoPilha){
    struct noPilha *noAtual = topoPilha;

    while (noAtual != NULL){
        cout << "Altura: " << noAtual->altura << " Idade: " << noAtual->idade << endl;
        noAtual = noAtual->proximoNo;
    }
    cout << "\nNULL";
}

int main(){

    struct noPilha *inicioPilha = NULL;
    int idade;
    float altura;

    cout << "*** Exercicio 6 em execucao*** Informe a altura em seguida idade\n\n";

    for (int i = 0; i < 3; i++){
        cin >> altura >> idade;
        inicioPilha = empilhar(inicioPilha, altura, idade);    
    }
    cout << "\n\n*** Pilha Atual ***\n\n";
    imprimirPilha(inicioPilha);

    while(inicioPilha != NULL){
        if(inicioPilha->altura > 1.90){
            cout << "\nAltura: " << inicioPilha->altura << "\nIdade: " << inicioPilha->idade << endl;
            inicioPilha = inicioPilha->proximoNo;
        }if (inicioPilha->altura < 1.90){
            inicioPilha = desempilhar(inicioPilha);
            cout << "\nJogador nao ira participar do campeonato" << endl;                     
        }
    }

    return 0;
}