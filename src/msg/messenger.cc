#include "messenger.h"


Messenger::Messenger(){

}

Messenger::~Messenger(){

}

Messenger* Messenger::create(MfsContext *mct, const std::string &type, std::string_view name){
    if(type.find("async") != std::string::npos){
        return new 
    }

    return nullptr;
}