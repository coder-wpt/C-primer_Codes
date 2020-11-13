#ifndef QUERYRESULT_HPP
#define QUERYRESULT_HPP
#include <memory>
#include <string>
#include <set>
#include <vector>

/*
 * @class QueryResult 接受TextQuery类中query函数返回的结果
 *
 * @param sought 需要查询的单词
 * @param lines 单词出现的行号集合set
 * @param file 输入的文件
 * */


class QueryResult
{
    friend std::ostream& print(std::ostream &os, const QueryResult&qr);
    using line_no = std::vector<std::string>::size_type;
public:
     QueryResult(std::string s,std::shared_ptr<std::set<line_no>> p,std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
private:
    std::string sought;//查询单词
    std::shared_ptr<std::set<line_no>>lines;//出现的行号
    std::shared_ptr<std::vector<std::string>>file;//输入文件
};

#endif
