#include "Stack.h"
#include "net_handler.h"

class PosixNetworkStack;

class PosixWorker: public Worker{
    mfs::NetHandler net;
    void initialize() override;
public:
    PosixWorker(MfsContext *m, unsigned worker_id)
        : Worker(m, worker_id), net(m) {}
    ~PosixWorker();
};

class PosixNetworkStack: public NetworkStack{
public:

    virtual Worker* create_worker(MfsContext *m, unsigned worker_id) override {
        return new PosixWorker(m, worker_id);
    }

    PosixNetworkStack(MfsContext *m);
    ~PosixNetworkStack();
};