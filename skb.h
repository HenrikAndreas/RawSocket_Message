#ifndef SKB_H
#define SKB_H

#include "mimir.h"
#include "libs.h"
#include "arp.h"
/*
The Socket Buffer Structure
*/
struct skb_buff {
    uint8_t eth_addr[ETHER_ALEN];
    struct interface* iface;
    struct node* arp_table;
    struct mimir* mimir;
    struct ip_hdr* ip;
    uint8_t* payload;
    char* ip_addr;
    // eth_header
};

#include "ip.h"

#endif