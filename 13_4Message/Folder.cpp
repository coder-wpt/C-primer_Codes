#include "Message.h"
#include "Folder.h"

Folder::Folder(const Folder& f):Messages(f.Messages)
{   
    FolderName = f.FolderName;
    addToMsg(f);    
}

Folder& Folder::operator=(const Folder& f)
{
    rmFromMsg(*this);
    Messages=f.Messages;
    addToMsg(f);
    return *this;
}

Folder::~Folder()
{
    rmFromMsg(*this);
}

void Folder::remMsg(Message *m)
{
    Messages.erase(m);
}

void Folder::addMsg(Message *m)
{
    Messages.insert(m);
}

void Folder::addToMsg(const Folder&f)
{
    for(auto M:f.Messages)
        M->save(*this);
}

void Folder::rmFromMsg(const Folder&f)
{
    for(auto M:f.Messages)
        M->remove(*this);

}

void swap(Folder &lhs,Folder &rhs)
{
    using std::swap;
    for(auto M:lhs.Messages)
        M->remove(lhs);
    for(auto M:rhs.Messages)
        M->remove(rhs);
    swap(lhs.Messages,rhs.Messages);
    for(auto M:lhs.Messages)
        M->save(lhs);
    for(auto M:lhs.Messages)
        M->save(rhs);
    
}
