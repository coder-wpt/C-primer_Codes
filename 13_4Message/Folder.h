#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <set>
class Message;

class Folder{
    friend void swap(Folder& lhs,Folder& rhs);
    friend class Message;
public:
    Folder(const std::string Fname = ""):FolderName(Fname){}
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void remMsg(Message*);
    void addMsg(Message*);
    std::string& getFldName(){return FolderName;}

private:
    void addToMsg(const Folder&);
    void rmFromMsg(const Folder&);
    std::string FolderName;
    std::set<Message*>Messages;

};


void swap(Folder &lhs,Folder &rhs);
#endif
