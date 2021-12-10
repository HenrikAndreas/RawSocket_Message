#ifndef MIMIR_H
#define MIMIR_H

#include "utils.h"
#include "eth.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define ETH_PRO_MIMIR 0xAB0111

struct mimir_hdr {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t length;
    // uint16_t checksum; might use later
};

int create_socket(int protocol);
void mimir_parse();
void mimir_send();

#endif
