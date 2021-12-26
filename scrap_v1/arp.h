#ifndef ARP_H
#define ARP_H

#include "ether.h"
#include "libs.h"

#define ARP_REQ 0x01
#define ARP_RES 0x00

/*
ARP - Address Resolution Protocol is here defined as a linked list
*/
struct node {
    struct node* next;
    struct arp* arp;
};
struct arp {
    uint8_t mac_dest[ETHER_ALEN];
    char* ip;
    char*name;

};


struct arp* create_arp_entry(char*, uint8_t[ETHER_ALEN]);
void add_connection(struct node*, struct arp*);
void print_arp_content(struct node*);
struct node* create_arp_table();
void cleanup_arp(struct node*);
void print_arps(struct node*);
void update_connection();
void remove_connection();
void find_connection();

#endif