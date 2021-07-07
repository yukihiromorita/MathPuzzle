#include <iostream>
#include <vector>

template<typename T, std::size_t size>
void f(T out[], const T (&in)[size])
{
    for (int n = 2; n <= 36; ++n)
    {
        int max = 0;
        for (std::size_t startIndex = 0; startIndex < size; ++startIndex)
        {
            std::vector<std::size_t> index;
            index.resize(n);
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                index[i] = startIndex + i;
                if (index[i] >= size)
                {
                    index[i] -= size;
                }
                sum += in[index[i]];
            }

            if (sum > max)
                max = sum;
        }
        out[n - 2] = max;
    }
}

int main()
{
    constexpr int europian[] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
    constexpr int american[] = {0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15, 3, 24, 36, 13, 1, 0, 27, 10, 25, 29, 12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2};

    int euroMax[35];
    int americanMax[35];
    f(euroMax, europian);
    f(americanMax, american);

    int count = 0;
    for (int n = 0; n < 35; ++n)
    {
        if (euroMax[n] < americanMax[n])
        {
            count++;
        }
    }

    std::cout << count << std::endl;
}