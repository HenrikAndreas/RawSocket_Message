#include "ip.h"

void ip_send(struct skb_buff* socket_buffer) {
    socket_buffer->ip->version = IPV4;
    socket_buffer->ip->ihl = 0x05;
    socket_buffer->ip->dscp = 0b000000;
    socket_buffer->ip->ecn =0b00;
    socket_buffer->ip->length = socket_buffer->mimir->mimir_length + sizeof(struct ip_hdr);
    socket_buffer->ip->id = 0x0000;
    socket_buffer->ip->flags = 0b000;
    socket_buffer->ip->frag_offset = 0b0000000000000;
    socket_buffer->ip->ttl = 0x40; 
    socket_buffer->ip->protocol = IPV4; 
    socket_buffer->ip->checksum = 0;

    socket_buffer->ip->dst_ip = ip_to_int(socket_buffer->ip_addr);
    socket_buffer->ip->src_ip = ip_to_int(socket_buffer->iface->iface_ipv4);

    printf("DEST: %u\n", socket_buffer->ip->dst_ip);
    printf("SRC: %u\n", socket_buffer->ip->src_ip);

}

/*
Converting string representation of IP to uint32_t
*/
uint32_t ip_to_int (const char * ip) {
    /* The return value. */
    unsigned v = 0;
    /* The count of the number of bytes processed. */
    int i;
    /* A pointer to the next digit to process. */
    const char * start;

    start = ip;
    for (i = 0; i < 4; i++) {
        /* The digit being processed. */
        char c;
        /* The value of this byte. */
        int n = 0;
        while (1) {
            c = * start;
            start++;
            if (c >= '0' && c <= '9') {
                n *= 10;
                n += c - '0';
            }
            /* We insist on stopping at "." if we are still parsing
               the first, second, or third numbers. If we have reached
               the end of the numbers, we will allow any character. */
            else if ((i < 3 && c == '.') || i == 3) {
                break;
            }
            else {
                return 0;
            }
        }
        if (n >= 256) {
            return 0;
        }
        v *= 256;
        v += n;
    }
    return v;
}
