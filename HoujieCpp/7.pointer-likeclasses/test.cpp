#include <iostream>
#include "My_shared_ptr.hpp"
using namespace std;

struct a
{
    void print()
    {
        cout << "out" << endl;
    }
};

int main()
{
    My_shared_ptr<a>A = new a;
    A->print();
    return 0;
}

