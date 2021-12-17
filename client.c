#include "ether.h"
#include "utils.h"
#include "sock_buff.h"

int main(int argc, char** argv) {

    verify_args(argc, argv);
    char* iface_name = "wlp0s20f3";
    uint8_t dest_mac[ETHER_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    struct arguments args = parse_args(argc, argv);

    int sock = create_sock(ETHER_P_MIMIR);
    struct sock_buff* skb = create_skb(iface_name);

    // TODO: Move into utils function
    if (strcmp(args.payload_flag, "-m") == 0) {
         skb->payload = args.payload;
         skb->size = strlen(skb->payload);
    } else if (strcmp(args.payload_flag, "-f") == 0) {
        printf("File Transmission is not yet supported...\n");
        free(skb->iface);
        free(skb);
        exit(EXIT_FAILURE);
    }


    // ?- init_skb(skb, msg, dest_mac)
    
    skb->eth_hdr = create_eth_hdr(skb->iface->iface_addr.sll_addr, dest_mac);

    send_eth(sock, skb);

    // Closing socket and deallocating memort
    close(sock);    
    free(skb->iface);
    free(skb->eth_hdr);
    free(skb);

    printf("\nSuccessfully terminated client...\n");
    return 0;
}
