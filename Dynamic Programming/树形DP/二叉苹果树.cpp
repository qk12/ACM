// Luogu 2015
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
struct Edge
{
    int to, dist;
};
vector<Edge> G[maxn];
int dp[maxn][maxn];
int n, q;
void addedge(int from, int to, int dist)
{
    G[from].push_back(Edge{to, dist});
}
void dfs(int u, int fa)
{
    for (auto &it : G[u])
    {
        int v = it.to, w = it.dist;
        if (v != fa)
        {
            dfs(v, u);
            for (int j = q; j >= 1; --j)
                for (int k = j - 1; k >= 0; --k)
                    dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + w);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c), addedge(b, a, c);
    }
    dfs(1, -1);
    printf("%d\n", dp[1][q]);
    return 0;
}