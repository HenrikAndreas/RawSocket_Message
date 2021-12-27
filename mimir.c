#include "mimir.h"

struct skb_buff* socket_buffer;

/*
Sending a message with the MIMIR protocol
*/
void mimir_send(int sock, char* ip, char* msg) {
    

    struct arp* dest_arp = find_arp(socket_buffer->arp_table, ip);
    if (dest_arp == NULL) {
        printf("ARP Match Not Found...\n");
        // ?- Send ARP REQ
        return;
    }

    printf("Found ARP with IP:\t%s\n", dest_arp->ip_addr);

    socket_buffer->payload = (uint8_t*) msg;

    socket_buffer->mimir->src_port = MIMIR_PORT;
    socket_buffer->mimir->dst_port = MIMIR_PORT;
    socket_buffer->mimir->mimir_length = sizeof(struct mimir) + strlen(msg);

    

    ip_send(socket_buffer);

    free(dest_arp);
}
/*
Initiating Socket Buffer and ARP Table
*/
void init_mimir() {
    socket_buffer = malloc(sizeof(struct skb_buff));
    socket_buffer->arp_table = create_arp_table();
    socket_buffer->mimir = malloc(sizeof(struct mimir));


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
    cleanup_arp(socket_buffer->arp_table);
    free(socket_buffer->mimir);
    free(socket_buffer);
    close(sock);
}