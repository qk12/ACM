// Luogu 1282
#include <bits/stdc++.h>
using namespace std;

int dp[1005][6005];
bool vs[1005][6005];
int w[1005];
int v[1005];

int main()
{
    int n, i, j;
    cin >> n;
    int base = 0; //base表示背包重量，就是初始重量，初始翻转次数
    int tot = 0;  //tot为背包体积

    int x, y;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x > y) //未翻过的骨牌重量就是1
        {
            v[i] = 2 * (x - y); //点数变化量看做体积
            w[i] = 1;
            tot += x - y;
        }
        if (y > x) //一开始翻过的骨牌重量就是-1
        {
            v[i] = 2 * (y - x);
            w[i] = -1;
            tot += y - x;
            base++; //初始重量
        }
    } //上下相同的骨牌就是体积为0，重量为0的物品，因为他们无论怎么翻，都不会对上下点数差造成影响

    //用体积为v的物体装总体积为tot的背包,装的体积尽量多的情况下，总重量w最小  背包重量为base
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= tot; j++)
        {
            dp[i][j] = dp[i - 1][j];
            vs[i][j] = vs[i - 1][j];
            if (vs[i - 1][j - v[i]] || j - v[i] == 0)
            {
                if (!vs[i][j])
                {
                    dp[i][j] = dp[i - 1][j - v[i]] + w[i];
                    vs[i][j] = 1;
                }
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    //printf("%d",base+dp[n][tot]);
    for (i = tot; i >= 1; i--) //找到第一个用所有物品可以装到的体积
        if (vs[n][i])
            break;

    printf("%d\n", base + dp[n][i]);
    return 0;
}