#include <string>
#include <memory>

#include "common/mfs_context.h"
#include "Event.h"

class NetworkStack;

class Worker{
public:
    MfsContext *mct;
    unsigned id;

public:
    EventCenter center;
public:
    Worker(MfsContext *m, unsigned worker_id);
    ~Worker();
    virtual void initialize() {}
};

class NetworkStack{
protected:
    MfsContext *mct;
    explicit NetworkStack(MfsContext *m);

public:
    NetworkStack(const NetworkStack &) = delete;
    static std::shared_ptr<NetworkStack> create(MfsContext *mct, const std::string &t);
    virtual Worker* create_worker(MfsContext *m, unsigned i) = 0; 
    void stop();
};