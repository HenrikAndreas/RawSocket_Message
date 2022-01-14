#include "ether.h"

void send_eth(struct skb_buff* socket_buffer) {
    printf("Sending Ethernet Packet...\n");

    int buf_size = sizeof(struct eth_header) + socket_buffer->ip->length;
    // int buf_size = sizeof(struct eth_header) + sizeof(struct ip_hdr);
    // copy on this format [Ethernet]-[IP]-[Mimir]-[Payload]
    uint8_t* buffer = (uint8_t*)malloc(buf_size);
    memset(buffer, 0, buf_size);


    memcpy(buffer, socket_buffer->eth, sizeof(struct eth_header));
    memcpy(buffer + sizeof(struct eth_header), socket_buffer->ip, sizeof(struct ip_hdr));
    int rc = sendto(socket_buffer->sock, buffer, buf_size, 0, (const struct sockaddr *)&(socket_buffer->iface->iface_addr), sizeof(struct sockaddr_ll));
    if (rc < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }


    free(buffer);
}