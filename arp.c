#include "arp.h"

struct arp* create_arp_table() {
    struct arp* arp = (struct arp*)malloc(sizeof(struct arp));
    memset(arp, 0, sizeof(struct arp));
    return arp;
}

void add_connection(struct arp* arp_table, struct arp* new_arp) {

    if (arp_table->ip == NULL) {
        printf("ARP Match not found. Creating entry...\n");
        // arp_table = malloc(sizeof(struct arp));
        memcpy(new_arp, arp_table, sizeof(struct arp));
    }

}

struct arp* create_arp_entry(char* ip, uint8_t mac[ETHER_ALEN]) {
    struct arp* arp_entry = (struct arp*)malloc(sizeof(struct arp));
    memset(arp_entry, 0, sizeof(struct arp));

    memcpy(arp_entry->mac_dest, mac, ETHER_ALEN);
    arp_entry->ip = ip;

    return arp_entry;
}