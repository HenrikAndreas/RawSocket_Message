#ifndef ARP_H
#define ARP_H

#include "ether.h"
#include "libs.h"

#define ARP_RES 0x00
#define ARP_REQ 0x01

/*
ARP - Defined as a linked list
*/
struct node {
    struct node* next;
    struct arp* arp;
};

struct arp {
    uint8_t eth_addr[ETHER_ALEN];
    char* ip_addr;
};

struct node* create_arp_table();

#endif