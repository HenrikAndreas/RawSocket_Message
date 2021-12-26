#include "arp.h"

/* 
Initiating the ARP Table
*/
struct node* create_arp_table() {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    memset(node, 0, sizeof(struct node));
    return node;
}