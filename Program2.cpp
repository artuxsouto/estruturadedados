#include <stdio.h>
#include <stdlib.h>

struct concursoVestibular{
	int codigoCurso;
	int nCandM; 
	int nCandF;
	int tVagas;
	
	int somar(){
		int calc = (nCandM + nCandF) / tVagas;
		return calc;
	}
};

int main(){
	
	printf("Ol�! Program2 em execu��o\n");
	
	int j = 0;	
	
	struct concursoVestibular vetorCursos[5];
	
	for (int i = 0; i < 5; i++){
		
	printf("\nDigite o c�digo do curso %d: ", i+1);
	scanf("%d", &vetorCursos[i].codigoCurso);
		
	printf("\nDigite o total de vagas: ");
	scanf("%d", &vetorCursos[i].tVagas);
		
	printf("\nDigite o n�mero de candidatos M: ");
	scanf("%d", &vetorCursos[i].nCandM);
	
	printf("\nDigite o n�mero de candidatos F: ");
	scanf("%d", &vetorCursos[i].nCandF);
	
	}
	for (int j = 0; j < 5; j++){
		printf("\nO curso %d:", j+1);
		printf("\nA rela��o � de %d candidatos por vaga\n", vetorCursos[j].somar());
	}
	int findCurso;
	printf("\nInform um c�digo de curso: ");
	scanf("%d", &findCurso);
	
	for (int n = 0; n < 5; n++){
		while (vetorCursos[n].codigoCurso == findCurso){
			printf("\nPossui %d vagas", vetorCursos[n].tVagas);
			printf("\nA rela��o � de [%d] candidatos por vaga\n", vetorCursos[n].somar());
			break;
		}
		if (n == 5){
			printf("\nCURSO INEXISTENTE");
		}
	}
	return printf("\n\nFIM!\n");
}
