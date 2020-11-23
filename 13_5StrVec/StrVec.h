#pragma once
#include <string>
#include <utility>
#include <memory>
class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);

    std::size_t size() const {return first_free - elements;}
    std::size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return cap;}

private:
    static std::allocator<std::string> alloc;//static member function for allocate memory

    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);//copy content from a to b and allocate memory

    void free();//will destory the constructed element and release the memory
    void reallocate();//allocate new memory for strvec when memory is used up
    void chk_n_alloc()//ensure that strvec has space for at least one new element
    {
        if( size() == capacity() )
        reallocate();
    }

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

