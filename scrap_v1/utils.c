#include "utils.h"

void verify_args(int argc, char** argv) {
    if ((argc < MIN_ARGS)) {
        printf("Usage: ./client -i <interface> -d <dest_ip> -m <msg>\n");
        exit(EXIT_FAILURE);
    }

}

void error_check(int val, char* tag) {
    if (val < 0) {
        perror(tag);
        exit(EXIT_FAILURE);
    }
}

struct arguments parse_args(int argc, char** argv) {
    struct arguments args;
    args.debug = 0;
    
    // Ignoring arg number 1. It is irrelevant
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            args.ip_dest = argv[++i];

        } else if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "-f") == 0) {
            args.payload_flag = argv[i];
            args.payload = argv[++i];

        } else if (strcmp(argv[i], "--debug") == 0) {
            args.debug = 1;
        } else if (strcmp(argv[i], "-i") == 0) {
            args.interface = argv[++i];
        }
    }

    printf("\n__Arguments__\n");
    printf("IP Destination: %s\n", args.ip_dest);
    printf("Payload Type: %s\n", args.payload_flag);
    printf("Payload: %s\n", args.payload);
    printf("Debug Mode: %d\n", args.debug);
    printf("Interface Mode: %s\n", args.interface);



    return args;

}
