#pragma once
#include <string>
#include <iostream>

class animal
{
public:
    animal(){
        std::cout << "animal constructor has been called" << std::endl;
    }
    virtual ~animal(){
        std::cout<< "animal destructor has been called" << std::endl;
    };
private:
};

class buru:public animal
{
public:
    buru(std::string Sex):sex(Sex){
        std::cout << "buru constructor has been called" << std::endl;
    }
    virtual ~buru(){
        std::cout<< "buru destructor has been called" << std::endl;
    };
    void fy();
private:
    std::string sex;
};


class human:public buru
{    
public:
    human(std::string Name,std::string Phone_num,std::string sex):buru(sex),name(Name),phone_num(Phone_num){
        std::cout << "humun constructor has been called" << std::endl;
    }

    virtual ~human()
    {
        std::cout << "humun destructor has been called" << std::endl;
    }
        
private:
    std::string name;
    std::string phone_num; 
};

//当一个成员函数的const和non-const
//版本同时存在，const object只会（只能）调用const版本
//non-const object只会（只能）调用non-const版本
