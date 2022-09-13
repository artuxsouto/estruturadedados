#include <stdio.h>
#include <stdlib.h>

struct dados{
	int idade;
	float altura;
};

int main(){
	
	struct dados pessoa[5];
	int idadeMaior = 0;
	int idadeMenor = 0;
	float alturaMenor = 0.0;
	int soma = 0;
	
	printf("Programa iniciando");
	
	for (int i = 0; i < 5; i++){
		printf("\nDigite a idade da pessoa %d: ", i + 1);
		scanf("%d", &pessoa[i].idade);
		
		printf("\nDigite a altura: ");
		scanf("%d", &pessoa[i].altura);
		
		if (idadeMaior < pessoa[i].idade){
			idadeMaior = pessoa[i].idade;
		}
		
		if (idadeMenor > pessoa[i].idade){
			idadeMenor = pessoa[i].idade;
			alturaMenor = pessoa[i].altura;
			
		}
		
		soma += pessoa[i].idade;
	}
	printf("\nA maior idade é: %d", idadeMaior);
	printf("\nA altura da menor idade é: %f", alturaMenor);
	printf("\nA media das idades é: %d", soma / 5);
	
	return 0;
}
