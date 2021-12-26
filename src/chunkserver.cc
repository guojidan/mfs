#include <stdlib.h>
#include <iostream>
#include <string>
#include "common/mfs_argparse.h"

using std::cerr;
using std::cout;

// start chunkserver service
int main(int argc, char* argv[]){
    // deal cmd args
    if(argc <= 1){
        cerr << ": -h or --help for usage" << std::endl;
    }

    auto a = argv_to_vec(argc, argv);
    return 0;
    // cout << a << std::endl;

    for(int i=1; i <argc; ++i){
        if(argv[i] == "-h"){
            cout << "1" <<std::endl;
        }
    }



args_err:
    return 0;
}