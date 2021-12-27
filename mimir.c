#include "mimir.h"

struct skb_buff* socket_buffer;

/*
Sending a message with the MIMIR protocol
*/
void mimir_send(int sock, char* ip, char* msg) {
    

    struct arp* dest_arp = find_arp(socket_buffer->arp_table, ip);
    if (dest_arp == NULL) {
        printf("ARP Match Not Found...\n");
        return;
    }

    printf("IP - %s\n", dest_arp->ip_addr);

    // add_connection(socket_buffer->arp_table, dest_arp);
    free(dest_arp);

    print_arps(socket_buffer->arp_table);


}
/*
Initiating Socket Buffer and ARP Table
*/
void init_mimir() {
    socket_buffer = malloc(sizeof(struct skb_buff));
    socket_buffer->arp_table = create_arp_table();

    uint8_t mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char* ip2 = "10.0.0.53";

    struct arp* new = create_arp_entry(ip2, mac);
    add_connection(socket_buffer->arp_table, new);
    free(new);


    uint8_t mac3[ETHER_ALEN] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
    char* ip3 = "10.0.0.70";

    struct arp* new3 = create_arp_entry(ip3, mac3);
    add_connection(socket_buffer->arp_table, new3);
    free(new3);

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
    free(socket_buffer);
    close(sock);
}