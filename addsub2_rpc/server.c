#include <stdio.h>
#include "addsub.h"

/* implementação da função add */
result * add_1_svc (operands *argp, struct svc_req *rqstp)
{
   static result r;

   printf ("Recebi chamado: add %d %d\n", argp->x, argp->y);
   sprintf(r.res, "%d", argp->x + argp->y);
   return (&r);
}

/* implementação da função sub */
result * sub_1_svc (operands *argp, struct svc_req *rqstp)
{
   static result r;

   printf ("Recebi chamado: sub %d %d\n", argp->x, argp->y);
   sprintf(r.res, "%d", argp->x - argp->y);
   return (&r);
}
