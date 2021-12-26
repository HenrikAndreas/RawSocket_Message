#include "arp.h"

struct node* create_arp_table() {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    memset(node, 0, sizeof(struct node));
    return node;
}

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

struct arp* create_arp_entry(char* ip, uint8_t mac[ETHER_ALEN]) {
    struct arp* arp_entry = (struct arp*)malloc(sizeof(struct arp));
    memset(arp_entry, 0, sizeof(struct arp));

    memcpy(arp_entry->mac_dest, mac, ETHER_ALEN);
    arp_entry->ip = ip;

    return arp_entry;
}

void print_arps(struct node* node) {

    printf("\n_______________________ ARP _______________________\n");
    print_arp_content(node);
    printf("_____________________________________________________\n");
}

void print_arp_content(struct node* node) {
    if (node->arp != NULL) {

        printf("IP: \t %s \t MAC: ", node->arp->ip);
        // Nicely printed IP and MAC addresses
        for (int i = 0; i<ETHER_ALEN-1; i++) {
            printf("%X:", node->arp->mac_dest[i]);
        }
        printf("%X\n", node->arp->mac_dest[ETHER_ALEN-1]);

        if (node->next != NULL) {
            print_arp_content(node->next);
        }
    }
}

/*
An iterative recursion to deallocate ARP Nodes
*/
void cleanup_arp(struct node* node) {
    struct node* tmp;

    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp->arp);
        free(tmp);
    }
}