#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5;
int d[maxn][maxn];
int dp[1 << maxn][maxn];
int n;
// 已经访问过的节点集合为S，当前位置为v
int dfs(int S, int v)
{
    if (dp[S][v] >= 0)
        return dp[S][v];
    if (S == (1 << n) - 1 && v == 0)
        return d[S][v] = 0; //已经访问过所有节点并回到0号点
    int res = INF;
    for (int u = 0; u < n; ++u)
        if (!(S >> u & 1)) //下一步移动到顶点u
            res = min(res, dfs(S | 1 << u, u) + d[v][u]);
    return dp[S][v] = res;
}
int solve()
{
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0);
}