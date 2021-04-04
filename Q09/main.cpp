#include <iostream>

int g_count = 0;

void f(int num, int man)
{
    // 今までの男女が同数なら抜ける
    if(num > 0 && num % 2 == 0 && num == man * 2)
    {
        return;
    }

    // 逆から数える
    int left = 30 - num;
    int leftman = 20 - man;
    if (num > 0 && left > 0 && left % 2 == 0 && left == leftman * 2)
    {
        return;
    }

    if (num == 30)
    {
        g_count++;
        return;
    }

    // 男配置
    if (num < 30 && man < 20)
    {
        f(num + 1, man + 1);
    }

    // 女配置
    if (num < 30 && (num - man) < 10)
    {
        f(num + 1, man);
    }

}

int main()
{
    f(1,1);
    f(1,0);
    std::cout << g_count << std::endl;
    return 0;
}