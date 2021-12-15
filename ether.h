#ifndef ETHER_H
#define ETHER_H

#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr, htons
#include <ifaddrs.h>		/* getifaddrs */

struct interface {
    struct sockaddr_ll iface_addr;
    char* iface_name;
    int iface_index;
};

void send_eth(int, char*, struct interface*);
struct interface* get_interface(char*);

#endif