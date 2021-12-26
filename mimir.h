#ifndef MIMIR_H
#define MIMIR_H

#include "libs.h"
#include "arp.h"
#include "skb.h"

#define MIMIR_PORT 0x01A4

struct mimir {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t mimir_length;
    uint16_t checksum;
};


int create_socket(uint16_t);
void cleanup_mimir(int);
void init_mimir();

#endif