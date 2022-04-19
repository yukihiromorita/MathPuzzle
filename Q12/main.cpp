#include <iostream>
#include <cmath>

// 10 個の配列がすべて true なら true を返す
bool digitCheck(bool* ary)
{
    for (int index = 0; index < 10; ++index)
    {
        if (ary[index] == false)
        {
            return false;
        }
    }

    return true;
}

// 12.34 -> 0.1234 にする
template<typename T>
T g(T number)
{
    int intDigit = static_cast<int>(std::floor(std::log10(number)) + 1);

    return number / std::pow(10, intDigit);
}

// 引数で受け取った数字の平方根に 0-9 の数字が出るまでの桁を返す
int f(int number, bool isIncludeIntPart)
{
    int count = 0;

    long double sqrt = std::sqrt(static_cast<long double>(number));

    if (isIncludeIntPart)
    {
        sqrt = g(sqrt);
    }
    else
    {
        const long double intPart = std::floor(sqrt);
        sqrt -= intPart;
    }

    // 平方根が整数
    if (sqrt < 0.00001)
    {
        return 0;
    }

    bool ary[10] = {false};
    while(true)
    {
        // 循環対策かつ枝切り
        if (count == 11)
        {
            break;
        }

        count++; // 桁を上げるのでインクリメント
        sqrt *= static_cast<long double>(10);

        const int intPart = static_cast<int>(std::floor(sqrt));
        ary[intPart] = true;

        bool result = digitCheck(ary);
        if (result)
        {
            break;
        }
        sqrt -= static_cast<long double>(intPart);
    }
    return count;
}

int main()
{
    for (int num = 2; num < 10000; ++num)
    {
        if (f(num, false) == 10) // 整数部分を含むかどうかは引数を変える
        {
            std::cout << num << std::endl;
            break;
        }
    }
}
