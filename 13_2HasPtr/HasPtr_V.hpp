#include <iostream>
#include <string>

class HasPtr
{
public:
    //构造函数：初始化默认值为空的string，分配在动态内存上
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
    //拷贝构造函数：用另一个HasPtr初始化，进行深拷贝 
    HasPtr(const HasPtr &p):ps(new std::string(*p.ps)),i(p.i){}
    //拷贝赋值操作副：进行深拷贝，注意自我赋值的问题
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
