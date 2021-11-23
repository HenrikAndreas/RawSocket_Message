#include "utils.h"


void verify_args(int argc, char** argv) {
    if (argc == 3) {
        return;
    }

    if (argc < 3) {
        printf("ERROR: Too few arguments!\n");
    } else if (argc > 3) {
        printf("ERROR: Too many arguments!\n");
    }
    printf("Correct usage: ./client <msg> <dest_addr>\n");
}