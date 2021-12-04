#include "mimir.h"
#include "eth.h"


int create_socket(int protocol) {
    int raw_sock = socket(AF_PACKET, SOCK_RAW, htons(protocol));
    return raw_sock;
}

