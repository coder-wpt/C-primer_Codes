#Composition(复合)
- 生命同步
##变压器Adapter(复合的特殊情况)
template<class T>
- queue中包含deque（复合）
- deque满足queue中所有需求的功能，用deque构造queue（适配器模式）

```
class queue{
...
protected:
    deque<T> C;

public:
    bool empty() const{ return C.empty(); }
    size_type size() const { return C.size(); }
    reference front() { return C.front(); }
    reference back() { return C.back(); }

    void push(const value_type& X){C.push_back(X);}
    void pop() {C.pop_front();}
}:
```

- 复合中构造有内而外，析沟由外而内


#Delegation(委托),Composition by reference
- 生命不同步
- 指针指向另一个对象
##handle/body（plmpl）
- 编译防火墙，handle中永远都不用再编译，只需要编译body部分

``` 
//file String.hpp
class StringRep;
class String{
public:
    String();
    String(const char* s);
    String(const String& s);
    String& operator=(const String& s);
    ~String();

pirvate:
    StringRep* rep;//pimpl
}

//file String.cpp
#include "String.hpp"
namesapce{
    class StringRep{
        friend class String;
        StringRep(const char* s);
        ~StringRep();
        int count;//引用计数
        char* rep;
    };
}

String::String(){}
```
- 共享状态下，多个对象共享一个内存，会有copy on right情况发生:其中一个对象需要改变内容的时候，需要拷贝一份出来。剩余对象继续共享

#Inheritance(继承)

- base中的析构函数必须是virtual
```
struct _List_node_base
{
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

template <typename _Tp>
struct _List_node : public _List_node_base
{
    _Tp _M_data;
}
```

- 构造由内而外：构造函数首先调用Base的default构造函数，然后再执行自己的
- 析构由外而内：析构函数首先执行自己，然后才调用base的析构函数
