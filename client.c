#include "ether.h"
#include "utils.h"



int main(int argc, char** argv) {

    verify_args(argc, argv);

    int sock = socket(AF_PACKET, SOCK_RAW, 0x88B5);
    error_check(sock, "socket");

    struct interface* iface = get_interface("wlp0s20f3");

    char* buffer = "The art of dying is the way to let all go";


    send_eth(sock, buffer, iface);
    // int rc = sendto(sock, buffer, strlen(buffer), 0, (const struct sockaddr *)&(iface->iface_addr), sizeof(struct sockaddr_ll));
    // error_check(rc, "sendto");
    // printf("Sent bytes:\t %d!\n", rc);




    close(sock);    
    free(iface);

    printf("\nSuccessfully terminated client...\n");
    return 0;
}