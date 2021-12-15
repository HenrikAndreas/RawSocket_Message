#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>

void verify_args(int argc, char** argv) {
    if ((argc != 3)) {
        printf("Usage: <FILL IN YOU BITCH>\n");
        exit(EXIT_FAILURE);
    }
}

void error_check(int val, char* tag) {
    if (val < 0) {
        perror(tag);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {

    verify_args(argc, argv);
    int sock;
    error_check(sock = (AF_INET, SOCK_RAW, 0x0b01), "SOCKET INIT");

    
    
    // Get 




    close(sock);    

    return 0;
}