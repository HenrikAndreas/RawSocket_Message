#include "ip.h"


void create_ip_hdr(struct sock_buff* skb) {

    struct ip_header ip_hdr;

    ip_hdr.version = IPV4;
    ip_hdr.ihl = 0x05;
    ip_hdr.tos = 0;
    // ip_hdr.len = sizeof(struct ip_header)
    ip_hdr.frag_offset = 0x4000;
    ip_hdr.ttl = 64;
    // ip_hdr.proto = skb->protocol;

}