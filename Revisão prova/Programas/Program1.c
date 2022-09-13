#include <stdio.h>
#include <stdlib.h>

struct dados{
	int idade;
	float altura;
};

int main(){
	
	struct dados pessoa[5];
	int idadeMaior = 0;
	int soma = 0;
	
	printf("Programa iniciando");
	
	for (int i = 0; i < 5; i++){
		printf("\nDigite a idade da pessoa %d: ", i + 1);
		scanf("%d", &pessoa[i].idade);
		
		printf("\nDigite a altura: ");
		scanf("%f", &pessoa[i].altura);
		
		if (idadeMaior < pessoa[i].idade){
			idadeMaior = pessoa[i].idade;
		}
		
		soma += pessoa[i].idade;
	}
	
	printf("\nA maior idade é: %d", idadeMaior);
	printf("\nA media das idades é: %d", soma / 5);
	
	return 0;
}
