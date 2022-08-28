all:
	rpcgen notas.x
	gcc server.c notas_svc.c -o server -lnsl
	gcc client.c notas_clnt.c -o client -lnsl

clean:
	rm -f client server notas_svc.c notas_clnt.c notas_xdr.c notas.h
