#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    int a=10;
    int *p=&a;
    if(p==nullptr)
    {
        exit(2);
    }
    cout<< *p<<endl;
    return 0;
}
