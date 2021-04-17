// solved myself

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using vec = std::pair<int, int>;
int g_count = 0;
constexpr int thre = 13; // 12回移動 = 配列は13個

void move(std::vector<vec>& posVec)
{
    if (posVec.size() == thre)
    {
        g_count++;
        return;
    }

    const auto& curPos = posVec.back();
    vec direction[4] = {std::make_pair(0,1), std::make_pair(0,-1), std::make_pair(1,0), std::make_pair(-1,0)};

    for (const auto& dire : direction)
    {
        auto pos = std::make_pair(curPos.first + dire.first, curPos.second + dire.second);
        if (std::find(posVec.begin(), posVec.end(), pos) == posVec.end())
        {
            auto newPosVec = posVec;
            newPosVec.push_back(pos);
            move(newPosVec);
        }
    }
}

int main()
{
    std::vector<vec> posVec;
    posVec.push_back(std::make_pair(0,0));
    move(posVec);
    std::cout << g_count << std::endl;
}
