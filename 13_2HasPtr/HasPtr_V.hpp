#include <string>

class HasPtr
{
    friend void swap(HasPtr &lhs,HasPtr &rhs);
public:
    //构造函数：初始化默认值为空的string，分配在动态内存上
    HasPtr(const std::string &s = std::string()):sp(new std::string(s)),i(0){}
    //拷贝构造函数：用另一个HasPtr初始化，进行深拷贝 
    HasPtr(const HasPtr &p):sp(new std::string(*p.sp)),i(p.i){}
    //拷贝赋值操作副：进行深拷贝，注意自我赋值的问题
/*    HasPtr& operator = (const HasPtr &p){
        std::string *temp = new std::string(*p.ps);
        delete ps;
        ps = temp;
        i=p.i;
        return *this;
    }
*/
    //"拷贝并交换技术"
    //将左侧运算对象与右侧运算对象的一个副本进行交换，本质上进行值传递相当于temp副本，同时避免了自我赋值的问题
    HasPtr& operator = (HasPtr p)
    {
        swap(*this,p);
        return *this;
    }
    ~HasPtr(){delete this->sp;}
private:
    std::string *sp;
    int i;
};


void swap(HasPtr &lhs,HasPtr &rhs)
{
    using std::swap;
    swap(lhs.sp,rhs.sp);
    swap(lhs.i,rhs.i);
}
