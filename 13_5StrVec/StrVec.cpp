#include <iostream>
#include "StrVec.h"

StrVec::StrVec(const StrVec& rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& s)
{
    auto newdata  = alloc_n_copy(s.begin(),s.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second; 
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string &str)
{
    chk_n_alloc();//ensure StrVec has space for new element
    alloc.construct(first_free++,str);//construct str's copy in the element pointed by first_free
}

std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* b,const std::string* e)
{
    auto data = alloc.allocate(e-b);//allocate enough space for e-b
    return {data,uninitialized_copy(b,e,data)};//initialize and return a pair consisting of the return value of data and uninitialized_copy
}

void StrVec::free()
{
    //can't transfer a null pointer to deallocate , if elements is nullptr then do nothing
    if(elements)
    {
        //destory old elements in reverse order
        for(auto p = first_free;p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap - elements);
    }
}

void StrVec::reallocate()
{
    //alloc menory space twice the current size
    auto newcapacity = size() ? 2 * size() : 1;
    //alloc new memory
    auto newdata = alloc.allocate(newcapacity);
    //get pointer point to the next free position in the new array  
    auto newelem = newdata;
    //get pointer point to the next element in the old array
    auto oldelem = elements;
    //construct element in new array 
    for(size_t i = 0; i!=size();++i)
        alloc.construct(newelem++,std::move(*oldelem++));
    free();
    elements = newdata;
    first_free = newelem;
    cap = elements + newcapacity;
}


