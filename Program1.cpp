#include <stdio.h>
#include <stdlib.h>

struct dadosClientes{
	int cdg;
	int idade;
	float salario;
};

int main(){
	
	struct dadosClientes vetorClientes[5];
	int menu;
	
	printf("Hello world! Program1");
	
	for (int i = 0; i < 5; i++){
		printf("\n\n Digite o c�digo do cliente %d: ", i+1);
		scanf("%d", &vetorClientes[i].cdg);
		
		printf("\n Digite a idade: ");
		scanf("%d", &vetorClientes[i].idade);
		
		printf("\n Digite o sal�rio: ");
		scanf("%f", &vetorClientes[i].salario);		
	}
	printf("\n 1- Exibir clientes\n 2- Consultar cliente\n 3- Sair do programa\n");
	scanf("%d", &menu);
	
	if (menu == 1){
		for (int j = 0; j < 5; j++){
			printf("\n\n C�digo do cliente %d: %d", j+1, vetorClientes[j].cdg);
			printf("\n Idade: %d", vetorClientes[j].idade);
			printf("\n Sal�rio: %f", vetorClientes[j].salario);
		}
	}else if (menu == 2){
			int b;
			printf("Digite o c�digo do cliente: ");
			scanf("%d", &b);
			
			for (int i = 0; i < 5; i++){
				if (vetorClientes[i].cdg == b){
					printf("\n\n C�digo do cliente: %d", vetorClientes[i].cdg);
					printf("\n Idade: %d", vetorClientes[i].idade);
					printf("\n Sal�rio: %f", vetorClientes[i].salario);
				}
			}
		}
		return printf("\n\nFIM!");
}
