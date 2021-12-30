#ifndef IP_H
#define IP_H

#include "libs.h"
#include "skb.h"

#define IPV4 0x04

struct ip_hdr {
    uint8_t version : 4;
    uint8_t ihl : 4;
    uint8_t dscp : 6;
    uint8_t ecn : 2;
    uint16_t length;
    uint16_t id;
    uint8_t flags : 3;
    uint16_t frag_offset : 13;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t dst_ip;
    uint32_t src_ip;

}__attribute__((packed));

uint32_t ip_to_int (const char*);
void ip_send(struct skb_buff*);

#endif