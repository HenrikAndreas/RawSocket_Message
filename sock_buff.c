#include "ether.h"
#include "sock_buff.h"

/*
Getting desired Network Interface to Transmit / Receive data
*/
struct interface* get_interface(char* name) {

    struct interface* iface = malloc(sizeof(struct interface));

    struct ifaddrs *ifaces, *ifp;
    int i = 0;

    error_check(getifaddrs(&ifaces), "getifaddrs");

    /* Iterating through all interfaces | Stops when interface is found */
    for (ifp = ifaces; ifp != NULL; ifp = ifp->ifa_next) {
        if (ifp->ifa_addr != NULL && ifp->ifa_addr->sa_family == AF_PACKET && strcmp(ifp->ifa_name, name) == 0) {
            memcpy(&(iface->iface_addr), ifp->ifa_addr, sizeof(struct sockaddr_ll));
            iface->iface_name = ifp->ifa_name;
            iface->iface_index = i;
        }
        i++;
    }

    free(ifaces);
    
    return iface;
}

/*
Initiation the Socket Buffer
*/
struct sock_buff* create_skb(char* iface_name) {
    struct sock_buff* skb = malloc(sizeof(struct sock_buff));
    
    // skb->eth_hdr = malloc(sizeof(struct eth_header));
    // memset(skb->eth_hdr, 0, sizeof(struct eth_header));

    skb->iface = get_interface(iface_name);

    return skb;
}

/*
Creating the Socket File Descriptor
*/
int create_sock(uint16_t protocol) {

    int sock = socket(AF_PACKET, SOCK_RAW, htons(protocol));
    error_check(sock, "socket");

    return sock;

}

/*
Initiation Socket Buffer with payload, and flags
*/
void init_skb(struct sock_buff* skb, struct arguments args) {
    if (strcmp(args.payload_flag, "-m") == 0) {
         skb->payload = args.payload;
         skb->size = strlen(skb->payload);
    } else if (strcmp(args.payload_flag, "-f") == 0) {
        printf("File Transmission is not yet supported...\n");
        free(skb->iface);
        free(skb);
        exit(EXIT_FAILURE);
    }
}