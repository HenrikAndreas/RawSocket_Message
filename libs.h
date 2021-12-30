#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for close
#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr, htons
#include <ifaddrs.h>		/* getifaddrs */
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
