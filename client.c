#include "libs.h"
#include "mimir.h"

int main(int argc, char** argv) {

    // Handle arguments

    // Initiate Socket
    int sock = create_sock(MIMIR_PORT);
    // Initiate ARP Table

    // Initiate Interface with MAC and IPv4 ( LAN )

    // Send argumnets message / file as MIMIR protocol
        // If Dest IP in ARP Table -> Create IP header -> Create ETH header PROTO (MIMIR REQ) -> send 



    return 0;
}