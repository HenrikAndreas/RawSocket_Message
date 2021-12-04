#include "utils.h"
#include "mimir.h"



int main(int argc, char** argv) {

    verify_args(argc, argv);

    uint8_t local_mac[6] = {0x00, 0x42, 0x38, 0xAD, 0x3B, 0x76};
    uint8_t dest_mac[6]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint16_t eth_type = ETHER_P_MIMIR;

    struct eth_headr* eth = malloc(sizeof(struct eth_headr));
    create_eth(eth, local_mac, dest_mac, eth_type);
    
    free(eth);
    
    printf("\nProgram Terminated...\n");
    return 0;
}
