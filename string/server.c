#include <stdio.h>
#include <string.h>
#include "notas.h"

#define NUM_ALUNOS 6

struct notas_s {
	char nome[50];
	double nota;
};

double *obtem_nota_1_svc(char **nome, struct svc_req *rqstp)
{
	static struct notas_s notas[NUM_ALUNOS] = {
		{"Alexandre", 9.5},
		{"Barbara",   8.5},
		{"Joao",      6.5},
		{"Maria",     9.0},
		{"Paulo",    10.0},
		{"Pedro",     7.0}
	};
	static double erro = -1.0;
	int i;

	for (i = 0; i < NUM_ALUNOS; i++)
		if (strcmp(notas[i].nome,*nome) == 0)
			return &(notas[i].nota);
	return &erro;
}
