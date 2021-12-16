#include "ether.h"
#include "utils.h"
#include "sock_buff.h"


int main(int argc, char** argv) {

    verify_args(argc, argv);
    char* msg = "The art of dying is the way to let all go";
    char* iface_name = "wlp0s20f3";
    uint8_t dest_mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};



    int sock = socket(AF_PACKET, SOCK_RAW, 0x88B5);
    error_check(sock, "socket");

    struct sock_buff* skb = create_skb(iface_name);
    skb->payload = msg;
    skb->size = strlen(skb->payload);
    
    skb->eth_hdr = create_eth_hdr(skb->iface->iface_addr.sll_addr, dest_mac);

    // // ?- free the buffer
    // char* buffer = create_eth_hdr(msg, iface->iface_addr.sll_addr, dest_mac);
    send_eth(sock, skb);


    // close(sock);    
    // free(iface);

    printf("\nSuccessfully terminated client...\n");
    return 0;
}
