#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr, htons
#include <ifaddrs.h>		/* getifaddrs */

void verify_args(int argc, char** argv) {
    if ((argc != 3)) {
        printf("Usage: <FILL IN YOU BITCH>\n");
        exit(EXIT_FAILURE);
    }
}

void error_check(int val, char* tag) {
    if (val < 0) {
        perror(tag);
        exit(EXIT_FAILURE);
    }
}


// FOR INTERFACE
struct interface {
    struct sockaddr_ll iface_addr;
    char* iface_name;
    int iface_index;
};

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

int main(int argc, char** argv) {

    verify_args(argc, argv);

    int sock = socket(AF_PACKET, SOCK_RAW, 0x88B5);
    error_check(sock, "INIT SOCKET");
    // error_check(sock = socket(AF_INET, SOCK_RAW, 0x88b5), "SOCKET INIT");

    struct interface* iface = get_interface("wlp0s20f3");

    char* buffer = "The art of dying is the way to let all go";

    int rc = sendto(sock, buffer, strlen(buffer), 0, (const struct sockaddr *)&(iface->iface_addr), sizeof(struct sockaddr_ll));
    error_check(rc, "sendto");
    printf("Sent bytes:\t %d!\n", rc);
    // printf("Interface Name:\t %s\n", iface->iface_name);
    // printf("Interface MAC:\t");
    // for (int i = 0; i < 6; i++) {
    //     printf("%X:", iface->iface_addr.sll_addr[i]);
    // }



    close(sock);    
    free(iface);

    printf("\nSuccessfully terminated client...\n");
    return 0;
}