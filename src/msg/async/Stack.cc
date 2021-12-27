#include <iostream>
#include <assert.h>

#include "Stack.h"
#include "PosixStack.h"
#include "Event.h"

Worker::Worker(MfsContext *m, unsigned worker_id)
    : mct(m), id(worker_id)
{
    
}

NetworkStack::NetworkStack(MfsContext *m)
    : mct(m)
{

}

std::shared_ptr<NetworkStack> NetworkStack::create(MfsContext *mct, const std::string &t){
    std::shared_ptr<NetworkStack> stack = nullptr;
    if (t == "posix"){
        stack.reset(new PosixNetworkStack(mct));
    }

    if(stack == nullptr){
        std::cerr << __func__ << "create NetworkStack err" << t <<
        "is not suported!" << std::endl;
        return nullptr;
    }

    unsigned num_worker = mct -> msg_async_op_threads;

    assert(num_worker > 0);
    if(num_worker > EventCenter::MAX_EVENTCENTER){
        std::cout << "max threads num will change to " <<
        EventCenter::MAX_EVENTCENTER << std::endl;
        num_worker = EventCenter::MAX_EVENTCENTER;
    }

    const int InitEventNumber = 5000;

    for(unsigned worker_id = 0; worker_id < num_worker; ++worker_id){
        Worker *w = stack -> create_worker(mct, worker_id);
        int ret = w -> center.init();
    }

}