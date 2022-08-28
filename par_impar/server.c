#include <stdio.h>
#include "par_impar.h"

int *par_impar_1_svc(int *valor, struct svc_req *rqstp)
{
	static int erro = -1;
	static int i;
	if((*valor) < 0)
		return &erro;

	i = (*valor) % 2 == 0;
	return &i;
}
