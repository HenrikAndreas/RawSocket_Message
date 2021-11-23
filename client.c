#include "utils.h"
#include "mimir.h"



int main(int argc, char** argv) {

    verify_args(argc, argv);

    int raw_sock = create_socket(ETH_PRO_MIMIR);
    

    return 0;
}
