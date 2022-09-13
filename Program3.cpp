#include <stdio.h>
#include <stdlib.h>

struct pessoas{
	int idade;
	float altura;
};

int main(){
	
	printf("Program3 em execução!\n");
	struct pessoas dados[5];
	int achouI = 0;
	int achouIN = 0;
	float alt = 0.0;
	int somar = 0;
	
	for (int i = 0; i < 5; i++){
		printf("\nDigite a idade da pessoa %d: ", i + 1);
		scanf("%d", &dados[i].idade);
		
		printf("\nDigite a altura: ");
		scanf("%f", &dados[i].altura);
		
		if (dados[i].idade > achouI){
			achouI = dados[i].idade;
		}else if (dados[i].idade < achouIN){
			achouIN = dados[i].idade;
			alt = dados[i].altura;			
		}
		somar += dados[i].idade;
	
	}
	
	printf("\nA pessoa mais velha tem: %d anos", achouI);
	printf("\nA altura da pessoa mais nova é: %.2f", alt);
	printf("\nA média aritmética das idades são: %d", somar / 5);
		
	return 0;
	
}
