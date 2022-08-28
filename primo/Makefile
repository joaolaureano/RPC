all:
	rpcgen primo.x
	gcc server.c primo_svc.c -o server -lnsl
	gcc client.c primo_clnt.c -o client -lnsl

clean:
	rm -f client server primo_svc.c primo_clnt.c primo_xdr.c primo.h
