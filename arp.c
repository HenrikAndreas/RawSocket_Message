#include "arp.h"

/* 
Initiating the ARP Table
*/
struct node* create_arp_table() {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    memset(node, 0, sizeof(struct node));
    return node;
}

/*
Adding connection to the ARP Table
*/
void add_connection(struct node* arp_table, struct arp* new_arp) {

    if (arp_table->arp == NULL) {
        printf("Creating ARP entry...\n");
        arp_table->arp = malloc(sizeof(struct arp));
        memcpy(arp_table->arp, new_arp, sizeof(struct arp));
        return;   

    }
    arp_table->next = malloc(sizeof(struct arp));
    memset(arp_table->next, 0, sizeof(struct arp));
    add_connection(arp_table->next, new_arp);

}

/*
Returning a new ARP entry
*/
struct arp* create_arp_entry(char* ip, uint8_t mac[ETHER_ALEN]) {
    struct arp* arp_entry = (struct arp*)malloc(sizeof(struct arp));
    memset(arp_entry, 0, sizeof(struct arp));

    memcpy(arp_entry->eth_addr, mac, ETHER_ALEN);
    arp_entry->ip_addr = ip;

    return arp_entry;
}

/*
Returning an ARP if match
*/
struct arp* find_arp(char* ip) {
    uint8_t mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    struct arp* matched_arp = create_arp_entry(ip, mac);
    
    return matched_arp;
}
