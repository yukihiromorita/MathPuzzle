#include <iostream>

template<typename T>
bool Check(T number)
{
    // 各桁の和
    T sum = 0;
    T digit = 1;
    while (true)
    {
        if (number / digit == 0)
        {
            break;
        }
        sum += (number / digit) % 10;
        digit *= 10;
    }

    return number % sum == 0;
}

int main()
{
   long ppx = 0;
   long px = 0;
   long x = 0;

    for (int i = 0; i < 100; ++i)
    {
        if (i == 0)
        {
            ppx = px = 0;
            x = 1;
        }
        else if (i == 1)
        {
            ppx = 0;
            px = 1;
            x = 1;
        }
        else
        {
            ppx = px;
            px = x;
            x = ppx + px;
        }

        if (Check<decltype(x)>(x))
        {
            std::cout << x << std::endl;
        }
    }
}