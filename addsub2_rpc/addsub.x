/* addsub.x : definição da interface */

#define PROGRAM_NUMBER 12345678
#define VERSION_NUMBER 1

/* tipo de dado que será passado aos procedimentos remotos */

struct operands
{
        int x;
        int y;
};

struct result
{
	char res[50];
};

/* definição da interface que será oferecida aos clientes */

program ADDSUB_PROG
{
   version ADDSUB_VERSION
   {
     result ADD (operands) = 1;
     result SUB (operands) = 2;
   }
   = VERSION_NUMBER;
}
= PROGRAM_NUMBER;
