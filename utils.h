#ifndef UTILS_H
#define UTILS_H

#include "libs.h"

#define MIN_ARGS 5

struct arguments {
    char* payload_flag;
    char* interface;
    char* payload;
    char* ip_dest;
    int debug;
};

struct arguments parse_args(int, char**);
void verify_args(int, char**);
void error_check(int, char*);
#endif