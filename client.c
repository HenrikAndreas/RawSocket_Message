#include "libs.h"
#include "mimir.h"

int main(int argc, char** argv) {

    // Handle arguments
    /*These two are temporary*/
    char* ip = "10.0.0.60";
    char* msg = "The art of dying is the way to let all go";

    // Initiate Socket
    int sock = create_socket(MIMIR_PORT);
    
    // Initiate ARP Table
    init_mimir();
    mimir_set_interface("wlp0s20f3");

    mimir_send(sock, ip, msg);
    // Initiate Interface with MAC and IPv4 ( LAN )

    // Send argumnets message / file as MIMIR protocol
        // If Dest IP in ARP Table -> Create IP header -> Create ETH header PROTO (MIMIR REQ) -> send 
    cleanup_mimir(sock);

    return 0;
}