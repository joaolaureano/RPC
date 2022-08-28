#include <stdio.h>
#include "par_impar.h"

/* função que chama a RPC add_1 */ 
int par_impar(CLIENT *clnt, int *value) {
	int *result;

	/* chama a função remota */
	result = par_impar_1(value, clnt);
	
	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -1;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	double nota;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <valor>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], PARIMPARPROG, PARIMPARVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	int value = atoi(argv[2]);
	nota = par_impar(clnt, &value);
	
	if (nota < 0)
		printf("Resultado: valor inválido!\n");
	else if(nota == 0)
		printf("Numero nao eh par");
	else if(nota == 1)
		printf("Numero eh par");
	
	return 0;
}
