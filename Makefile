CLIENT_ARGS = Hello! 127.0.0.1
C_FILES = $(find *.c)

all: client

client: ${C_FILES}
	gcc -g -o out/client *.c && ./out/client $(CLIENT_ARGS)
val_client:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./out/client ${CLIENT_ARGS}
clean:
	rm -rf out/*