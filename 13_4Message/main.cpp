#include "Folder.h"
#include "Message.h"

int main()
{
    Message m1(std::string("m1"));
    Message m2(std::string("m2"));
    Message m3(std::string("m3"));

    Folder f1;
    Folder f2;
    
    f1.addMsg(&m1);
    f1.addMsg(&m2);
    f2.addMsg(&m3);

    return 0;
}
