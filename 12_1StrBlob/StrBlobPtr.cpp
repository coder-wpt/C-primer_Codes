#include "StrBlobPtr.hpp"
#include <string>


std::string& StrBlobPtr::deref() const
{
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::invr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    std::cout<<curr<<std::endl;
    return *this;
}
