#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include <fstream>
#include <iostream>
using namespace std;

string make_plural(size_t ctr,const string &word,const string &ending)
{
    return (ctr > 1)? word+ending : word;
}

ostream &print(ostream &os ,const QueryResult &qr)
{
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "<<make_plural(qr.lines->size(),"time","s")<<std::endl;
    for(auto num : *qr.lines)
        os << "\t(line "<< num + 1 <<")"<< *(qr.file->begin() + num)<<endl;
    return os;
}

void runQueries(ifstream &infile)
{
    //infile是需要处理的文件
    TextQuery tq(infile);//保存文件并且建立查询set
    //与用户交互：提示用户输入要查询的单词，完成拆查询并打印结果
    while(true)
    {
        std::cout<<"enter word to look for , or q to quit:";
        std::string s;
        //遇到文件尾部或者用户输入q时循环中止
        if(!(std::cin>>s) || s == "q")break;
        print(std::cout,tq.query(s))<<endl;
    }
}


int main()
{
    ifstream test;
    test.open("./test.txt");
    runQueries(test);
    return 0;
}
