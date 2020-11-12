#ifndef STRBLOBPTR_HPP
#define STRBLOBPTR_HPP
#include "StrBlob.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class StrBlobPtr
{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob & a,std::size_t sz=0):wptr(a.data),curr(sz){}
    std::string& deref() const;
    StrBlobPtr& invr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i,const std::string& msg)const
    {
        auto ret=wptr.lock();
        if(!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if(i>=ret->size())
            throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<std::vector<std::string>>wptr;
    std::size_t curr;
};
#endif
