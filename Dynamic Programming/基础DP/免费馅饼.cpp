// HDU 1176
#include <bits/stdc++.h>
using namespace std;

int dp[100001][11]; //dp[i][j]表示第i时刻在第j位置时能收到的最多馅饼数

int main()
{
    int n;
    int x, t;
    while (scanf("%d", &n), n != 0)
    {
        int end = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &t);
            ++dp[t][x];
            end = max(end, t);
        }
        for (int i = end - 1; i >= 0; --i)
        {
            for (int j = 1; j <= 9; ++j)
            {
                dp[i][j] += max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
            }
            dp[i][0] += max(dp[i + 1][0], dp[i + 1][1]);
            dp[i][10] += max(dp[i + 1][10], dp[i + 1][9]);
        }
        printf("%d\n", dp[0][5]);
    }
    return 0;
}
