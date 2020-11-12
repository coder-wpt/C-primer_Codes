#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
#include <iostream>

using namespace std;

int main()
{
    StrBlob b1;
    {
        StrBlob b2={"a","an","the"};
        b1=b2;
        b2.push_back("about");
        cout<<b2.size()<<endl; 
    }
    cout<<b1.size()<<endl;
    StrBlobPtr sbp1(b1,2);
    auto ret=sbp1.deref();
    cout<<ret<<endl;
    auto ret1=sbp1.invr();
    auto ret2=ret1.deref();
    cout<<ret2<<endl;
    return 0;
}
