#include "libs.h"
#include "mimir.h"

int main(int argc, char** argv) {

    // Handle arguments
    /*These two are temporary*/
    char* ip = "10.0.0.60";
    char* msg = "The art of dying is the way to let all go";
    char* interface = "wlp0s20f3"
    // Initiate Socket
    int sock = create_socket(MIMIR_PORT);
    
    // Initiate ARP Table
    init_mimir();

    // Initiate Interface with MAC and IPv4 ( LAN )
    mimir_set_interface(interface);

    mimir_send(sock, ip, msg);

    // Send argumnets message / file as MIMIR protocol
        // If Dest IP in ARP Table wlp0s20wlp0s20f3f3wlp0s20f3-> Create IP header -> Create ETH header PROTO (MIMIR REQ) -> send 
    cleanup_mimir(sock);

    return 0;
}