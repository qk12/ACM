// POJ 2342
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 6e3 + 5;
vector<int> G[maxn];
int dp[maxn][maxn];

void dfs(int u, int fa)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (v != fa)
        {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

int deg[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &dp[i][1]);
    int l, k;
    while (scanf("%d%d", &l, &k), l + k)
    {
        G[k].push_back(l);
        ++deg[l];
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
        {
            root = i;
            break;
        }
    dfs(root, -1);
    int ans = max(dp[root][0], dp[root][1]);
    printf("%d\n", ans);
    return 0;
}