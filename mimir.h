#ifndef MIMIR_H
#define MIMIR_H

#include "libs.h"
#include "arp.h"
#include "skb.h"
#include "ip.h"

#define MIMIR_PORT 0x01A4

struct mimir {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t mimir_length;
    uint16_t checksum;
};

void print_mimir_hdr(struct mimir*);
void mimir_send(int, char*, char*);
int create_socket(uint16_t);
void cleanup_mimir(int);
void init_mimir();

#endif