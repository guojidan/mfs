#include "mfs_context.h"

namespace mfs {
    class NetHandler {
    public:
        MfsContext *mct;
    public:
        explicit NetHandler(MfsContext *m): mct(m) {}
        ~NetHandler();
    };
}