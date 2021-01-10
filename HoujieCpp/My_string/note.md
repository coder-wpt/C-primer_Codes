# My_string
## Features example
```
int main()
{
    string s1();
    string s2("hello");

    string s3(s1);
    cout << s3 << endl;
    s3 = s2;

    cout << s2 << endl;

}
```
- note:complex类中，没有拷贝构造和拷贝赋值？
- 因为编译器会为你创造，忠实地为你一个一个拷贝。
- 但是指针类，如果还是忠实地进行一个一个拷贝指针，就会出现多个指针指向同一个object的情况

##Big_three 三个特殊函数  
```
class My_string
{
public:
    My_string(const char* cstr = 0);
    My_string(const My_string& str);
    My_string& operator = (const My_string& str);
    ~My_string();

    char* get_c_str() const{return m_data;}
private:
    char* m_data;
}
```


### copy ctor:  My_string(const My_string& str)
- 判断传入指针是否为空
- 分配空间，复制字符串
```
string s1("hello");
string s2=s1;
string s3(s1);
//s2和s3都调用copy ctor
```

### copy My_string& operator = (const My_string& str)
- 检测自我赋值(如果不写，那么会出现不可预料的错误)
- 1.清空原有空间
- 2.申请一块新的内存空间
- 3.将需要拷贝的object拷贝过来

### ~My_string()
- 释放分配的空间

##output
```
ostream& operator<<(ostream& os,const string &str)
{
    os << str.get_c_str();
    return os;
}
```

# new:先分配memory，再调用ctor
- void*men operator new( sizeof(Complex) );
- pc = static_cast<complex*>(mem);
- pc->Complex::Complex(1,2);  

# delete:先调用dtor，再释放memory
- complex:~complex(pc);
- operator delete(pc);

# new[]delete[]
- 如果使用了delete,只会delete一个对象内存。（指针类对象数组存在内存泄漏的风险）
