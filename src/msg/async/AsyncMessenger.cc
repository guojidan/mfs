#include "AsyncMessenger.h"

struct StackSingleton{
    MfsContext *mct;

    std::shared_ptr<NetworkStack> stack;
    explicit StackSingleton(MfsContext *c): mct(c){}

    void ready(std::string &type){
        if (!stack){
            stack = NetworkStack::create(mct, type);
        }
    }

    ~StackSingleton(){
        stack -> stop();
    }
};

AsyncMessenger::AsyncMessenger(){

}

AsyncMessenger::~AsyncMessenger(){

}