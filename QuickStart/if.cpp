/*
输入一个非递减的正整数数组，如：
11 11 45 56
应该输出：
11 2次
45 1次
56 1次
*/
#include <iostream>

int main()
{

    int prev=0, curr=0, cnt=0;

    while (std::cin >> curr)
    {
        if (prev == 0)
        {
            prev = curr;
            cnt = 1;
            continue;
        }

        if (prev != curr)
        {
            std::cout << prev << "  @ " << cnt << std::endl;
            prev = curr;
            cnt = 1;
        }
        else
        {
            cnt += 1;
        }

    }
    std::cout << prev << "  @ " << cnt << std::endl;

    return 0;
}
