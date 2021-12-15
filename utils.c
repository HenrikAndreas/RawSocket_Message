#include "utils.h"

void verify_args(int argc, char** argv) {
    if ((argc != 3)) {
        printf("Usage: <FILL IN YOU BITCH>\n");
        exit(EXIT_FAILURE);
    }
}

void error_check(int val, char* tag) {
    if (val < 0) {
        perror(tag);
        exit(EXIT_FAILURE);
    }
}

