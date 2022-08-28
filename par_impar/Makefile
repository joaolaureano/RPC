all:
	rpcgen par_impar.x
	gcc server.c par_impar_svc.c -o server -lnsl
	gcc client.c par_impar_clnt.c -o client -lnsl

clean:
	rm -f client server par_impar_svc.c par_impar_clnt.c par_impar_xdr.c par_impar.h
