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

    socket_buffer->payload = (uint8_t*) msg;

    socket_buffer->mimir->src_port = MIMIR_PORT;
    socket_buffer->mimir->dst_port = MIMIR_PORT;
    socket_buffer->mimir->mimir_length = sizeof(struct mimir) + strlen(msg);
    socket_buffer->mimir->checksum = 0;
    
    print_mimir_hdr(socket_buffer->mimir);
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
    socket_buffer->ip = malloc(sizeof(struct ip_hdr));

    uint8_t mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char* ip = "10.0.0.60";
    struct arp* new_arp = create_arp_entry(ip, mac);
    add_connection(socket_buffer->arp_table, new_arp);
    free(new_arp);
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
    free(socket_buffer->ip);
    free(socket_buffer);
    close(sock);
}

void print_mimir_hdr(struct mimir* hdr) {
    printf("\nMimir Header\n_______________________________\n");
    printf("SRC Port: \t %d \t 0x%X\n", hdr->src_port, hdr->src_port);
    printf("DEST Port: \t %d \t 0x%X\n", hdr->dst_port, hdr->dst_port);
    printf("Mimir Length:\t %d\n", hdr->mimir_length);
    printf("Mimir Checksum:\t %d\n", hdr->checksum);
}