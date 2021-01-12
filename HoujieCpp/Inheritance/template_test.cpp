#include <iostream>
#include "template.hpp"
using namespace std;

int main()
{
    CMyDoc* c1 = new CMyDoc;
    c1->OnFileOpen();
    
    CSVDataParse* c2 = new CSVDataParse;
    c2->process();
    return 0;
}

