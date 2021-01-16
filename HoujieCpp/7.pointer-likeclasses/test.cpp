#include <iostream>
#include "My_shared_ptr.hpp"
using namespace std;

class a
{
public:
    void print()
    {
        cout << "out" << endl;
    }
    ~a()
    {
        cout << "a destructor has been used" <<endl;
    }
};

int main()
{
    {
    Shared_ptr<a>A = new a;
    Shared_ptr<a>B = A;
    cout << A.getref() <<endl;
    cout << B.getref() <<endl;
    {
        Shared_ptr<a>C = A;
        Shared_ptr<a>D = B;
        cout << C.getref() << endl;
        cout << D.getref() << endl;
    }
    cout << A.getref() <<endl;
    cout << B.getref() <<endl;
    return 0;
    }
    
}

