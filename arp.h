#ifndef ARP_H
#define ARP_H

#include "ether.h"
#include "libs.h"


struct arp {
    struct arp_table* next;
    uint8_t mac_dest[ETHER_ALEN];
    char* ip;
    char*name 

};

struct arp* create_arp_table();
void update_connection();
void remove_connection();
void find_connection();
void add_connection();

#endif