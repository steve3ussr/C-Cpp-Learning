/*
使用while循环来求解50-100的和；
*/

# include <iostream>

int main()
{
    int s=0, i=50;
    int limit = 100;
    while (i <= limit)
    {
        s += i++;
    }
    std::cout << "前" << limit << "个数字的和是：" << s << std::endl;
}