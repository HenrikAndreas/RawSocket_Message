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

struct arp* create_arp_entry(char*, uint8_t[ETHER_ALEN]);
void add_connection(struct node*, struct arp*);
struct arp* find_arp(struct node*, char*);
void print_arp_content(struct node*);
struct node* create_arp_table();
void cleanup_arp(struct node*);
void print_arps(struct node*);

#endif