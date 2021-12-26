#ifndef MIMIR_H
#define MIMIR_H

#include "libs.h"

#define MIMIR_PORT 0x01A4

/*
The Mimir Protocol Header
*/
struct mimir {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t mimir_length;
    uint16_t checksum;
}__attribute__((packed));


int create_sock(uint16_t);

#endif