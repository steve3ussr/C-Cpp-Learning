/*
求解1-10的和；
*/
#include <iostream>

int main()
{
    int s=0;
    int i=0;
    for (;i<=10;i++)
    {
        s += i;
    }
    std::cout << s;
    return 0;
}