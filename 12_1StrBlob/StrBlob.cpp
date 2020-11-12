#include "StrBlob.hpp"

void StrBlob::pop_back()
{
    check(0,"no menber in StrBlob");
    data->pop_back();
}

std::string StrBlob::front()
{
    check(0,"no member in StrBlob");
    return data->front();
}

std::string StrBlob::back()
{
    check(0,"no member in StrBlob");
    return data->back();
}
