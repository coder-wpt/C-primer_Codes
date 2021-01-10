#include <iostream>
#include "My_string.h"


int main()
{
    My_string s1();
    My_string s2("hello");
    My_string s3 = s2;
    My_string s4 = "abc";

   cout<<s1<<s2<<s3<<s4<<endl; 
   
    s4 = s3;

    cout<<s1<<s2<<s3<<s4<<endl;

   return 0;
}

