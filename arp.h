#ifndef ARP_H
#define ARP_H

#include "ether.h"
#include "libs.h"

/*
ARP - Address Resolution Protocol is here defined as a linked list
*/
struct arp {
    struct arp* next;
    uint8_t mac_dest[ETHER_ALEN];
    char* ip;
    char*name;

};

struct arp* create_arp_entry(char*, uint8_t[ETHER_ALEN]);
void add_connection(struct arp*, struct arp*);
struct arp* create_arp_table();
void update_connection();
void remove_connection();
void find_connection();


#endif