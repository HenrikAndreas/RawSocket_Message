CLIENT_ARGS = Hello! 127.0.0.1

all: client

client: client.c
	gcc -g -o out/client client.c && ./out/client $(CLIENT_ARGS)

clean:
	rm -rf out/*