#include "ether.h"
#include "utils.h"
#include "sock_buff.h"
#include "arp.h"
int main(int argc, char** argv) {

    verify_args(argc, argv);
    // char* iface_name = "wlp0s20f3";
    uint8_t dest_mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    struct arguments args = parse_args(argc, argv);

    int sock = create_sock(ETHER_P_MIMIR);
    struct sock_buff* skb = create_skb(args.interface);

    init_skb(skb, args);


    // ARP 
    struct arp* arp_table = create_arp_table();
    struct arp* new = create_arp_entry(args.ip_dest, dest_mac);
    add_connection(arp_table, new);
    // Search for ARP entry
        // If IP - ARP hit
            // Send to arp MAC
        // Else
            // Send broadcast

    // If recieved check protocol
        // If ARP req...
        // If ARP res..
        // IF MIMIR req..
        // If MIMIR res..       

    // ?- init_skb(skb, msg, dest_mac)
    
    skb->eth_hdr = create_eth_hdr(skb->iface->iface_addr.sll_addr, dest_mac);

    send_eth(sock, skb);

    // Closing socket and deallocating memort
    close(sock);    
    free(skb->iface);
    free(skb->eth_hdr);
    free(skb);
    free(arp_table->next);
    free(arp_table);

    printf("\nSuccessfully terminated client...\n");
    return 0;
}
