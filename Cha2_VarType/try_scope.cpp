#include <iostream>

unsigned x=114514;

int main()
{
    std::cout << x << std::endl;

    std::string x = "qwer";
    std::cout << x << std::endl;
    std::cout << ::x << std::endl;
    return 0;
}