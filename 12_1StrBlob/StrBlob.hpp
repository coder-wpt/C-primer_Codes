#ifndef STRBLOB_HPP
#define STRBLOB_HPP


#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include "StrBlobPtr.hpp"

class StrBlob
{
    friend class StrBlobPtr;
    public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob():data(std::make_shared<std::vector<std::string>>()){}
    StrBlob(std::initializer_list<std::string>Str_list):data(std::make_shared<std::vector<std::string>>(Str_list)){}

    size_type size()const{return data->size();}
    bool empty()const{return data->empty();}

    void push_back(const std::string &t){data->push_back(t);}
    void pop_back();

    std::string front();
    std::string back();

private:
    std::shared_ptr<std::vector<std::string>>data;
    void check(size_type i,const std::string &msg)const
    {
        if(i>data->size())
            throw std::out_of_range(msg);
    }
};

#endif
