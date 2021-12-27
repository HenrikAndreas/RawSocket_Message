#ifndef SKB_H
#define SKB_H

#include "mimir.h"
#include "libs.h"
#include "arp.h"
/*
The Socket Buffer Structure
*/
struct skb_buff {
    struct node* arp_table;
    struct mimir* mimir;
    uint8_t* payload;
    // ip_header
    // eth_header
    // net_interface
};

#endif