#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include "Folder.h"

class Message
{
    friend class Folder;
    friend void swap(Message &lhs,Message &rhs);
public:
    explicit Message(const std::string &str =""):contents(str){}// constructor
    Message(const Message&);//copu constructor
    Message& operator=(const Message&);//copy operator
    ~Message();//distructor function
    void save(Folder&);//insert this message into the folder
    void remove(Folder&);//remove this messsage form the folder
private:
    std::string contents; //email_contents;
    std::set<Folder*>folders;//set of folder

    void add_to_Folders(const Message&);//add the message into all folders who are in the set of folder
    void remove_from_Folders(); //remove the message from all folders who have the message
};

void swap(Message &lhs,Message &rhs);//swap function

#endif 
