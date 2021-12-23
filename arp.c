#include "arp.h"

struct node* create_arp_table() {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    memset(node, 0, sizeof(struct node));
    return node;
}

void add_connection(struct node* arp_table, struct arp* new_arp) {

    if (arp_table->arp == NULL) {
        printf("ARP Match not found. Creating entry...\n");
        arp_table->arp = malloc(sizeof(struct arp));
        memcpy(arp_table->arp, new_arp, sizeof(struct arp));
    }

}

struct arp* create_arp_entry(char* ip, uint8_t mac[ETHER_ALEN]) {
    struct arp* arp_entry = (struct arp*)malloc(sizeof(struct arp));
    memset(arp_entry, 0, sizeof(struct arp));

    memcpy(arp_entry->mac_dest, mac, ETHER_ALEN);
    arp_entry->ip = ip;

    return arp_entry;
}