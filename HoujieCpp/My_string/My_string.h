#pragma once
#include<string.h>
#include<iostream>
using namespace std;
class My_string
{
public:
    My_string(const char* cstr = 0); 
    My_string(const My_string& str);
    My_string& operator=(const My_string& str);
    ~My_string();

    char* get_c_str() const {return m_data;}
    
private:
    char* m_data;
};

inline
My_string::My_string(const char* cstr)
{
    if(cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data,cstr);
    }else{
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
My_string::~My_string()
{
    delete[] m_data;
}

inline
My_string::My_string(const My_string& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
}


My_string& My_string::operator=(const My_string& str)
{

    if(this == &str)//判断是否是自拷贝(address)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
    return *this;
}

ostream& operator<<(ostream& os , const My_string&str){
    return os<<str.get_c_str();
}


