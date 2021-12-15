#include "ether.h"

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

char* create_eth_hdr(char* msg, uint8_t src[ETHER_ALEN], uint8_t dest[ETHER_ALEN]) {
    char* buffer = malloc(sizeof(struct eth_header));
    memset(buffer, 0, sizeof(struct eth_header));

    // ?- A cleaner implementation perhaps

    return msg;
}

void send_eth(int sock, char* buffer, struct interface* iface) {

    int rc = sendto(sock, buffer, strlen(buffer), 0, (const struct sockaddr *)&(iface->iface_addr), sizeof(struct sockaddr_ll));
    error_check(rc, "sendto");

}