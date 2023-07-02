#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

struct Dp
{
    float money;
    int from;
};

struct Path
{
    int from;
    int to;
};

int main()
{
    int n;
    cin >> n;

    vector<float> p(n);
    for (auto& pi : p)
    { cin >> pi; }

    vector<vector<Dp>> dp(3, vector<Dp>(n));

    for (auto& dpi : dp[0])
    { dpi = {1, -1}; }

    for (int row = 1; row < 3; ++row)
    {
        for (int to = row; to < n; ++to)
        {
            Dp maxDp = {0, -1};
            for (int from = row - 1; from < to; ++from)
            {
                Dp currentDp = {dp[row - 1][from].money / p[from] * p[to], from};
                if (currentDp.money > maxDp.money)
                { maxDp = currentDp; }
            }

            if (dp[row][to - 1].money > maxDp.money)
            { dp[row][to] = {dp[row][to - 1].money, -1}; }
            else
            { dp[row][to] = maxDp; }
        }
    }

    int iMax = 0, jMax = 0;
    float moneyMax = dp[iMax][jMax].money;
    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            if (dp[i][j].money > moneyMax)
            {
                iMax = i;
                jMax = j;
                moneyMax = dp[iMax][jMax].money;
            }
        }
    }

    stack<Path> path;
    while (iMax > 0 && jMax >= 0)
    {
        while (dp[iMax][jMax].from == -1)
        { --jMax; }
        path.push({dp[iMax][jMax].from + 1, jMax + 1});
        jMax = dp[iMax][jMax].from - 1;
        --iMax;
    }

    cout << path.size() << "\n";
    while (!path.empty())
    {
        cout << path.top().from << " " << path.top().to << "\n";
        path.pop();
    }
}
