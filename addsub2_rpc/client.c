/* Cliente RPC simples */

#include <stdio.h>
#include "addsub.h"

/* função que chama a RPC add_1 */
char *add (CLIENT *clnt, int x, int y)
{
   operands ops;
   result *r;

   /* junta os parâmetros em um struct */
   ops.x = x;
   ops.y = y;

   /* chama a função remota */
   r = add_1 (&ops,clnt);
   if (r == NULL)
   {
     printf ("Problemas ao chamar a função remota\n");
     exit (1);
   }

   return (r->res);
}

/* função que chama a RPC sub_1 */
char *sub (CLIENT *clnt, int x, int y)
{
   operands ops;
   result *r;

   /* junta os parâmetros em um struct */
   ops.x = x;
   ops.y = y;

   /* chama a função remota */
   r = sub_1 (&ops,clnt);
   if (r == NULL)
   {
      printf ("Problemas ao chamar a função remota\n");
      exit (1);
   }
   return (r->res);
}

int main( int argc, char *argv[])
{
   CLIENT *clnt;
   int x,y;

   /* verifica se o cliente foi chamado corretamente */
   if (argc!=4)
   {
      fprintf (stderr,"Usage: %s hostname num1 num2\n",argv[0]);
      exit (1);
   }

   /* cria uma struct CLIENT que referencia uma interface RPC */
   clnt = clnt_create (argv[1], ADDSUB_PROG, ADDSUB_VERSION, "udp");

   /* verifica se a referência foi criada */
   if (clnt == (CLIENT *) NULL)
   {
      clnt_pcreateerror (argv[1]);
      exit(1);
   }

   /* obtém os dois inteiros que serão passados via RPC */
   x = atoi (argv[2]);
   y = atoi (argv[3]);

   /* executa os procedimentos remotos */
   printf ("%d + %d = %s\n", x, y, add (clnt,x,y));
   printf ("%d - %d = %s\n", x, y, sub (clnt,x,y));

   return (0);
}
