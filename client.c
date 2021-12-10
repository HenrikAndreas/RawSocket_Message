#include "utils.h"
#include "mimir.h"

#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */


int main(int argc, char** argv) {

    verify_args(argc, argv);

    uint8_t local_mac[6] = {0x70, 0xcd, 0x0d, 0x97, 0xbc, 0x60};
    uint8_t dest_mac[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint16_t eth_type = ETHER_P_MIMIR;

    struct eth_headr* eth = malloc(sizeof(struct eth_headr));
    create_eth(eth, local_mac, dest_mac, eth_type);

    int sock = create_socket(ETH_PRO_MIMIR);
    if (sock < 1) {
        perror("SOCKET");
        exit(0);
    }

    char* buf = "The art of dying is to let all go\n";

    struct sockaddr_ll addr;
    memset(&addr, 0, sizeof(struct sockaddr_ll));
    memcpy(&addr.sll_addr, dest_mac, ETHER_A_LEN);

    for (int i = 0; i < ETHER_A_LEN; i++) {
        printf("%X:", addr.sll_addr[i]);
    }
    printf("\n");

    int sent = sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&addr,sizeof(struct sockaddr_ll));
    if (sent < 0) {
        perror("SENDTO");
        exit(0);
    }
    close(sock);
    free(eth);
    
    printf("\nProgram Terminated...\n");
    return 0;
}
