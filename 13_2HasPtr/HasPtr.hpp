#include <iostream>
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new std::string(*p.ps)),i(p.i){}
    HasPtr& operator = (const HasPtr &p){
        std::string *temp = new std::string(*p.ps);
        delete ps;
        ps = temp;
        i=p.i;
        return *this;
    }

    ~HasPtr(){delete this->ps;}
private:
    std::string *ps;
    int i;
};
