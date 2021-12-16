#ifndef ETHER_H
#define ETHER_H

#include "sock_buff.h"
#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr, htons
#include <ifaddrs.h>		/* getifaddrs */

#define ETHER_ALEN 6


struct eth_header {
    uint8_t ether_dhost[ETHER_ALEN];
    uint8_t ether_shost[ETHER_ALEN];
    uint16_t protocol;
} __attribute__((packed));

struct eth_header* create_eth_hdr(uint8_t[ETHER_ALEN], uint8_t[ETHER_ALEN]);
void send_eth(int, struct sock_buff*);

#endif