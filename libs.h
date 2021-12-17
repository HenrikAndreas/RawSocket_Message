#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr, htons
#include <ifaddrs.h>		/* getifaddrs */