#include "mfs_argparse.h"

std::vector<const char*> argv_to_vec(int argc, const char* const* argv){
    assert(argc > 0);
    return {argv + 1, argv + argc};
}