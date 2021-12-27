#include <string>

class EventCenter{
public:
    static const int MAX_EVENTCENTER = 24;
public:
    int init(int nevent, unsigned center_id, const std::string &type);
};