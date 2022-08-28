#include <stdio.h>
#include "primo.h"

int *primo_1_svc(int *valor, struct svc_req *rqstp)
{
	static int erro = -1;
	static int result = 1;
	int _valor = (*valor);
	
	if(_valor < 0){
		 return &erro;
	}

	int i;

	if(_valor == 1){
		return &result;
	}

	for(i = 2; i < _valor; i++){
		if(_valor % i == 0 ){
			result = 0;
			break;
		}
	}

	return &result;
}