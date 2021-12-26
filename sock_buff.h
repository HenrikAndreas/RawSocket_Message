#ifndef SOCK_BUFF_H
#define SOCK_BUFF_H

#include "sock_buff.h"
#include "libs.h"
#include "ip.h"

#define ETHER_ALEN 6


struct sock_buff {
    struct interface* iface;
    struct eth_header* eth_hdr;
    struct ip_header* ip;
    char* payload;
    int size;
    // arp hdr
    // mimir hdr | application header | layer 5
    // uint16_t protocol;
};

struct interface {
    struct sockaddr_ll iface_addr;
    char* iface_name;
    int iface_index;
};

void init_skb(struct sock_buff*, struct arguments);
struct interface* get_interface(char*);
struct sock_buff* create_skb(char*);
int create_sock(uint16_t);

#endif