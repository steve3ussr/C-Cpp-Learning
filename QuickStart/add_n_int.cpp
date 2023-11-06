// 从stdin中读取不定长的整数，打印和
#include <iostream>

int main()
{
    int s=0, v;
    while (std::cin >> v)
    {
        s += v;
        std::cout << s << std::endl;
    }
    std::cout << s << std::endl;
    return 0;
}
