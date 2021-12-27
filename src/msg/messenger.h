#include <string>
#include <string_view>

#include "common/mfs_context.h"


class Messenger
{
private:
    /* data */
public:
    Messenger(/* args */);
    ~Messenger();

    Messenger* create(MfsContext *mct, const std::string &type, std::string_view name);
};

