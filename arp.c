
struct arp* create_arp_table() {
    struct arp* = (struct arp*)malloc(sizeof(struct arp));
    memset(arp, 0, sizeof(struct arp));

    return arp;
}
