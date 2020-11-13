#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include "QueryResult.hpp"

class QueryResult;//返回类型，需要先定义
class TextQuery
{
public:
    using line_no=std::vector<std::string>::size_type;//便于阅读，取别名
    TextQuery(std::ifstream&);//构造函数
    QueryResult query(const std::string&)const;//接受string，返回结果
private:
    std::shared_ptr<std::vector<std::string>>file;//保存读如的文件
    std::map<std::string,std::shared_ptr<std::set<line_no>>>wn;//保存单词和对应的行号set
};

#endif
