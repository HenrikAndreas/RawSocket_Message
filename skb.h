#ifndef SKB_H
#define SKB_H

#include "libs.h"

/*
The Socket Buffer Structure
*/
struct skb_buff {
    struct node* arp_table;
    // ip_header
    // mimir_header
    // eth_header
    // net_interface
};

#endif