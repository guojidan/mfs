#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "common/mfs_argparse.h"

using std::cerr;
using std::cout;

const std::string usage = "todo";

// start chunkserver service
int main(int argc, char* argv[]){
    // deal cmd args
    if(argc <= 1){
        cerr << ": -h or --help for usage" << std::endl;
    }

    auto argc_vec = argv_to_vec(argc, argv);

    for(auto arg : argc_vec){
        if(strcmp(arg, "-h") == 0){
            cout << usage << std::endl;
            goto help;
        }
        if(strcmp(arg, "--config") == 0){
            
        }
    }

    

args_err:
    return 0;
help:
    cout << "exit" << std::endl;
    return 0;
}