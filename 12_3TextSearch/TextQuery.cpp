#include "TextQuery.hpp"
#include <sstream>

TextQuery::TextQuery(std::ifstream &is):file(new std::vector<std::string>)
{
    std::string text;//暂存一行
    while(getline(is,text))//循环获取一行
    {
        file->push_back(text);//将一行加入file中
        int n=file->size()-1;//获取当前行的行号
        std::istringstream line(text);//创建istringstream对象，将text分解为单词
        std::string word;//暂存单词
        while(line>>word)//读取单词
        {
            auto &lines = wn[word];//map返回一个shared_ptr<set<line_no>>
            if(!lines)//如果为空，说明单词第一次出现，创建一个新的set
                lines.reset(new std::set<line_no>);
            lines->insert(n);//将当前行号插入set
        }
    }
}


QueryResult TextQuery::query(const std::string &sought)const
{
    //如果没有找到sought，我们将返回一个指向此set的指针
    static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
    
    //使用find而不是下标运算符来查找查找单词，避免将单词添加到wm中
    auto loc=wn.find(sought);
    if(loc == wn.end())
        return QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);
}
