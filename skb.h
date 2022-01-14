#ifndef SKB_H
#define SKB_H

#include "libs.h"
#define ETH_ALEN 6

/*
The Socket Buffer Structure
*/
struct skb_buff {
    struct interface* iface;
    struct node* arp_table;
    struct eth_header* eth;
    struct mimir* mimir;
    struct ip_hdr* ip;
    uint8_t* payload;
    char* ip_addr;
    int sock;
};

#include "ether.h"
#include "mimir.h"
#include "ip.h"

#endif