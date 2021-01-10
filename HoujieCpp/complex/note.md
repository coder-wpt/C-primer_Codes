##guard programming
```c++
#ifdefine __COMPLEXE__
#define __COMPLEXE__

class ostream; 
class complex;//forward declarations(前置声明)

class complex//class declarations(类-声明)
{
... 
};

complex::function //class definition(类-定义)
#endif
```
##class template
``` template<typename T> 
class complex
{
private: T re,im;
}

{
    complex<double>c1(2.4,1.5);
    complex<int>c2(2,6);
}
```

##inline function
写在类内的函数成为inline函数的候选人
类外 inline关键字

## constructor
//default argument默认实参
//inilization list
//没有 return type
```c++
complex(double r = 0, double i = 0):re(r),im(r){}
```

##constructor放到pirvate里头(singleton)
- constructor put in private 
- declare static function "getinstence" to create A
- declare static A a
 
```
class A{
public:
static A&getInstence();
void setup();

private:
    A();
    A(const A& rhs);
}
A& getInstence()
{
    static A a;
    return a;
}
```

##成员函数后面的const
不可改变成员变量

##pass by value,pass by reference
- pass by value：如果大小太大影响效率
- pass by reference:引用大小4字节（主要用来做参数传递和返回值）
- 最好用pass by reference
- const reference 不能改变原有值 改了之后编译会出错

##friend
- 类的封装，保证类内数据的安全性(friend破坏了c++的封装性)
- 特别的 声明了frined函数，就可以直接自由取得friend的private成员
- 相同class的各个object互为friends(友元函数)

##对于一个类考虑如下几点
- 数据放在private中
- 参数尽可能使用by reference传递(const 看情况添加)
- 返回值尽量用reference
- 在类的本体里面，函数应该加const的就要加，如果不加使用者使用的时候会报错
- inilizatino list 尽量使用

##return type （reference?）
- 相加结果存放在第一个实参中 return by reference
```
inline complex& _doapl(complex& c1,const complex& c2)
{
    c1->re += c2.re;
    c1->im += c2.im;
    return *c1;
}
```
- question? 上述函数返回的是一个object，但是返回类型为引用，对吗？
- 对的。传递者无需知道接受者是以reference接受的。
- 相加结果存放在新的变量中 return by value
```
inline complex _doapl(cosnt complex& c1,const complex& c2)
{
    complex temp;
    temp.re = c1.re+c2.re;
    temp.im = c1.im+c2.im;
    return temp;
}
```

##operator overloading(1 member function)
- member function including this pointer
- c3+=c2+=c1 连串赋值：返回类型不能为void
```
inline complex& complex::operator += (const complex& r)
{
    return _doapl(this , r);
}
```

##operator overloading(2 no member function)
- no member function has not this pointer

##temp object（return by value）
```C++
inline complex operator + (const complex& x,const complex& y)
{
    return complex (real(x)+real(y),imag(x)+imag(y));
}

inline complex operator + (const complex& x,double y)
{
    return complex (real(x) + y,imag(x));
}

inline complex operator + (double x,const complex& y)
{
    return complex (x + real(y), imag(y));
}
```
- 这些函数绝对不可以 return by reference，因为，它们返回的必定是个local object

##operator<<
- os不能设置为const，每一次输出都在改变os的状态
```
inline ostream& operator << (ostream& os,const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

{
    complex c1(2,1);
    cout<<conj(c1);
    cout<<c1<<conj(c1);//返回值应该为ostream类型，可以继续输出
}
```

##complex类的实现
- costructor inlization list
- const
- pass by value/reference(to const)
- return by value/reference
- data put in private mostly
- function put in public mostly
