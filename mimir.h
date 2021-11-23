#include "utils.h"

#include <sys/socket.h>
#include <arpa/inet.h>

#define ETH_PRO_MIMIR 0xAB0111
#define ETH_ADR_LEN 6

void check_error(int condition, char* tag);
int create_socket(int protocol);