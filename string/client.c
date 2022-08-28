#include <stdio.h>
#include "notas.h"

/* função que chama a RPC add_1 */ 
double obtem_nota(CLIENT *clnt, char *str) {
	double *result;

	/* chama a função remota */
	result = obtem_nota_1(&str, clnt);
	
	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -1.0;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	double nota;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <nome>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], NOTASPROG, NOTASVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	nota = obtem_nota(clnt, argv[2]);

	if (nota < 0.0)
		printf("Resultado: nome nao encontrado!\n");
	else
		printf("Nota: %.1lf\n", nota);
	
	return 0;
}
