#include "ip.h"

void ip_send(struct skb_buff* socket_buffer) {
    socket_buffer->ip->version = IPV4;
    socket_buffer->ip->ihl = 0x05;
    socket_buffer->ip->dscp = 0b000000;
    socket_buffer->ip->ecn =0b00;
    socket_buffer->ip->length = socket_buffer->mimir->mimir_length + sizeof(struct ip_hdr);
    socket_buffer->ip->id = 0x0000;
    socket_buffer->ip->flags = 0b000;
    socket_buffer->ip->frag_offset = 0b0000110100100;
    socket_buffer->ip->ttl = 0x40;
    socket_buffer->ip->protocol = IPV4;
    socket_buffer->ip->checksum = 0;

}