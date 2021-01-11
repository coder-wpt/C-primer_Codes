#pragma once
#include<iostream>
using namespace std;

class CDocument 
{
public:
    void OnFileOpen()
    {
        cout << "dialog..." << endl;
        cout << "check file status ..."<< endl;
        cout << "open file" <<endl;
        Serialize();
        cout << "close file ..." <<endl;
        cout << "update all views..." <<endl;
    }

    virtual void Serialize(){};

};

class CMyDoc : public CDocument
{
public:
    virtual void Serialize()
    {
        //只有应用程序自己才知道如何读取自己的文件（格式）
        cout << "CMyDoc::Serialize()" << endl;
    }
};
