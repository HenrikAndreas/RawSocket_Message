CLIENT_ARGS = -d 10.0.0.52 -m "Gojira"
C_FILES = $(find *.c)

all: compile client

compile:
	gcc -g -o out/client *.c
client: ${C_FILES}
	./out/client $(CLIENT_ARGS)
val_client:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./out/client ${CLIENT_ARGS}
clean:
	rm -rf out/*