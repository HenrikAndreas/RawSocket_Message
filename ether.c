#include "ether.h"


struct eth_header* create_eth_hdr(char* msg, uint8_t src[ETHER_ALEN], uint8_t dest[ETHER_ALEN]) {

    
    struct eth_header* eth_hdr = malloc(sizeof(struct eth_header));
    memcpy(eth_hdr->ether_shost, src, ETHER_ALEN);
    memcpy(eth_hdr->ether_dhost, dest, ETHER_ALEN);
    eth_hdr->protocol = 0x88B5; // ?- Set to ETH_P_MIMIR
}

void send_eth(int sock, struct sock_buff* skb) {
    int buf_size = sizeof(skb->size) + sizeof(struct eth_header);
    char* buffer = malloc(buf_size);
    memset(buffer, 0, buf_size);

    // Copying over data from sk_buff to buffer
    
    int rc = sendto(sock, buffer, skb->size, 0, (const struct sockaddr *)&(skb->iface->iface_addr), sizeof(struct sockaddr_ll));
    error_check(rc, "sendto");

}