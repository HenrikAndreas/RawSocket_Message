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
struct arp* find_arp(struct node* arp_table, char* ip) {
    if (arp_table == NULL) {
        printf("ARP Match Failed...\n");
        return NULL;
    }
    if (arp_table->arp != NULL && !strcmp(arp_table->arp->ip_addr, ip)) {
        printf("ARP Match Found...\n");

        struct arp* matched_arp = malloc(sizeof(struct arp));
        memset(matched_arp, 0, sizeof(struct arp));
        matched_arp->ip_addr = ip;
        memcpy(matched_arp->eth_addr, arp_table->arp->eth_addr, ETHER_ALEN);
        return matched_arp;
        
    }

    find_arp(arp_table->next, ip);
    
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



void print_arps(struct node* node) {

    printf("\n_______________________ ARP _______________________\n");
    print_arp_content(node);
    printf("_____________________________________________________\n");
}

void print_arp_content(struct node* node) {
    if (node->arp != NULL) {

        printf("IP: \t %s \t MAC: ", node->arp->ip_addr);
        // Nicely printed IP and MAC addresses
        for (int i = 0; i<ETHER_ALEN-1; i++) {
            printf("%X:", node->arp->eth_addr[i]);
        }
        printf("%X\n", node->arp->eth_addr[ETHER_ALEN-1]);

        if (node->next != NULL) {
            print_arp_content(node->next);
        }
    }
}