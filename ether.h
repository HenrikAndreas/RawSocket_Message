#ifndef ETH_H
#define ETH_H

#include "libs.h"

#define MIMIR_PROTO 0x88B5
#define IPV4_PROTO 0x0800
#define ARP_PROTO 0x0806
#define ETHER_ALEN 6

struct eth_header {
    uint8_t eth_dst[ETHER_ALEN];
    uint8_t eth_src[ETHER_ALEN];
    uint16_t protocol;
};

#include "skb.h"

void send_eth(struct skb_buff*);

#endif