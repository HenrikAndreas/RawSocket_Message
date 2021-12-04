#ifndef ETH_H
#define ETH_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ETHER_P_MIMIR 0xA0FD
#define ETHER_HDR_LEN 14
#define ETHER_A_LEN 6

struct eth_headr {
    uint8_t src_mac[ETHER_A_LEN];
    uint8_t dst_mac[ETHER_A_LEN];
    uint16_t eth_type;
}__attribute__((packed));

void create_eth(struct eth_headr* eth, uint8_t src[ETHER_A_LEN], uint8_t dst[ETHER_A_LEN], uint16_t type);
void send_eth(int sock);


#endif