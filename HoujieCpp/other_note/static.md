#static data members
- 单独存储 

#static member functions
- 成员函数需要隐含传入的this指针
- 静态函数也只有一份
- 通过object调用，或者通过类名调用

```
class account{
public:
    static double m_rate;
    static void set_rate(const double& x){m_rate = x;}
};
double Account::m_rate = 8.0;

int main(){
    Account::set_rate(5.0);

    Account a;
    a.set_rate(7.0);
}

```

#Singleton
## meyers Singleton
```
class A{
public:
    static A& getInstance();
    setup(){...}
private:
    A();
    A(const A& rhs);
    ...
}

A& A::getInstance()//把静态对象放在函数里面，只要当调用到的时候才会生成对象
{
    static A a;
    return a;
}
```

#cout
- 一种 ostream

#class template,类模板//代码的膨胀，多份代码
```
template<typename T>
class complex
{
public:

};

{
    complex<double>c1(2.5,1.5);
    complex<int>c2(2,6);
}
```

#function template,函数模板//标准库中algroithm
```
template<class T>
inline
const T& min(const T&a, const T& b)
{
    return b < a ? b : a;//具体比较交给操作符重载
}

```

#namesapce
- using directive:using namesapce std;//封锁全部打开
- using declaration:std::cout;//一个一个打开

#更多细节的深入
1.operator type() const
- 一般的
```
type1 i;
type2 d;
i = (type1)d;
```
通过隐式类型转换运算符：
```
operator double(){
    return static_cast<double>(sum)/static_cast<double>(num);
}
```
可以直接写成i=d

2.explicit
- 禁止隐式转换

3.pointer-like object

4.function-like object

5.namesapce





