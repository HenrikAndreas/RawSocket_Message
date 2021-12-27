#include "mimir.h"

struct skb_buff* socket_buffer;

/*
Sending a message with the MIMIR protocol
*/
void mimir_send(int sock, char* ip, char* msg) {
    
    struct arp* dest_arp = find_arp(ip); // UNFINISHED
    free(dest_arp);

}
/*
Initiating Socket Buffer and ARP Table
*/
void init_mimir() {
    socket_buffer = malloc(sizeof(struct skb_buff));
    socket_buffer->arp_table = create_arp_table();
}

/*
Creating the Socket File Descriptor
*/
int create_socket(uint16_t protocol) {

    int sock = socket(AF_PACKET, SOCK_RAW, htons(protocol));
    if (sock < 0) {
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }

    printf("Created Socket:\t <0x%X>\n", protocol);

    return sock;

}

/*
Deallocating memory
*/
void cleanup_mimir(int sock) {
    free(socket_buffer->arp_table);
    free(socket_buffer);
    close(sock);
}