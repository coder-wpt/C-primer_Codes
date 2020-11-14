#include <iostream>
#include <string>

class HasPtr
{
public:
    //构造函数，在动态内存上创建对象，计数为1
    HasPtr(const std::string &str = std::string()):sp(new std::string(str)),i(0),use_count(new std::size_t(1)){}
    //拷贝构造，拷贝指针，不拷贝对象本身。拷贝对象后引用技术需要+1
    HasPtr(const HasPtr &p):sp(p.sp),i(p.i),use_count(p.use_count){++*use_count;}
    //拷贝赋值操作符，右侧计数加一，左侧计数减一，减一后要判断是否需要释放对象 
    //如果是自赋值，那么先对右边++后对左边--的操作就可以避免出现未定义的问题 
    HasPtr& operator=(const HasPtr &p)
    {
        ++*(p.use_count);
        if(--*use_count==0)
        {
            delete sp;
            delete use_count;
        }
        sp =p.sp;
        i = p.i;
        use_count=p.use_count;
        return *this;
    }
    ~HasPtr()
    {
        if(--*use_count==0)
        {
            delete sp;
            delete use_count;
        }
    }
private:
    std::string *sp;
    int i;
    std::size_t *use_count;
};
