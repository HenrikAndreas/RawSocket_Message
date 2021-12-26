#include "mimir.h"

/*
Creating the Socket File Descriptor
*/
int create_sock(uint16_t protocol) {

    int sock = socket(AF_PACKET, SOCK_RAW, htons(protocol));
    if (sock < 0) {
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }

    return sock;

}
