#include "eth.h"

void create_eth(struct eth_headr* eth, uint8_t src[ETHER_A_LEN], uint8_t dst[ETHER_A_LEN], uint16_t type) {
        memset(eth->src_mac, 0, ETHER_A_LEN);
        memset(eth->dst_mac, 0, ETHER_A_LEN);

        memcpy(eth->src_mac, src, ETHER_A_LEN);
        memcpy(eth->dst_mac, dst, ETHER_A_LEN);
        eth->eth_type = type;

        printf("Created ethernet header...\n");
}

