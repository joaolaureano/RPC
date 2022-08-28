#include <stdio.h>
#include "primo.h"

/* função que chama a RPC add_1 */ 
int primo(CLIENT *clnt, int *value) {
	int *result;

	/* chama a função remota */
	result = primo_1(value, clnt);
	
	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -1;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	double resultado;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <valor>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], PRIMOPROG, PRIMOVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	int value = atoi(argv[2]);
	resultado = primo(clnt, &value);

	if (resultado < 0)
		printf("Resultado: valor inválido!\n");
	else if(resultado == 1)
		printf("Numero eh primo\n");
	else if(resultado == 0)
		printf("Numero nao eh primo\n");
	
	return 0;
}
