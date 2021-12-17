#ifndef ETHER_H
#define ETHER_H

#include "sock_buff.h"
#include "libs.h"

#define ETHER_ALEN 6


struct eth_header {
    uint8_t ether_dhost[ETHER_ALEN];
    uint8_t ether_shost[ETHER_ALEN];
    uint16_t protocol;
} __attribute__((packed));

struct eth_header* create_eth_hdr(uint8_t[ETHER_ALEN], uint8_t[ETHER_ALEN]);
void send_eth(int, struct sock_buff*);

#endif