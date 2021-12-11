#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>

void verify_args(int argc, char** argv) {
    if ((argc > 2) || (argc < 2)) {
        printf("Usage: <FILL IN YOU BITCH>\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {

    verify_args(argc, argv);

    int sock = (AF_INET, SOCK_RAW, 0x0b01);
    if (sock < 0) {
        perror("SOCKET INIT");
        exit(EXIT_FAILURE);
    }
    
    // Sockaddr_ll





    close(sock);    

    return 0;
}