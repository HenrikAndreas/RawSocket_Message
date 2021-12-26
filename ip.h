#ifndef IP_H
#define IP_H

#include "sock_buff.h"
#include "libs.h"

#define IPV4 0x04

struct ip_header {
    uint8_t ihl : 4;
    uint8_t version : 4;
    uint8_t tos;
    uint16_t len;
    uint16_t id;
    uint16_t frag_offset;
    uint8_t ttl;
    uint8_t proto;
    uint16_t csum;
    uint32_t src_addr;
    uint32_t dest_addr;
} __attribute__((packed));

void create_ip_hdr(struct sock_buff* skb);

#endif

