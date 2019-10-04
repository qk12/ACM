#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct edge
{
    int to, w;
};

typedef pair<int, int> PII;
const int maxn = 4e4 + 5;
vector<edge> G[maxn];
vector<int> sp;
int dep[maxn], dfn[maxn];
PII dp[21][maxn << 1];
void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
    sp.clear();
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (int i = 0; i < G[u].size(); ++i)
    {
        edge temp = G[u][i];
        if (temp.to == fa)
            continue;
        dfs(temp.to, u);
        sp.push_back(u);
    }
}
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++)
        dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r)
        swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
}

int dis[maxn];
void dfs2(int u, int fa, int dist)
{
    dis[u] = dist;
    for (int i = 0; i < G[u].size(); ++i)
    {
        edge it = G[u][i];
        int v = it.to, w = it.w;
        if (v != fa)
            dfs2(v, u, dist + w);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int x, y, w;
    char s[10];
    while (m--)
    {
        scanf("%d%d%d%s", &x, &y, &w, s);
        G[x].push_back(edge{y, w});
        G[y].push_back(edge{x, w});
    }
    dfs2(1, -1, 0);
    dfs(1, -1);
    initrmq();
    int k;
    scanf("%d", &k);
    int u, v;
    while (k--)
    {
        scanf("%d%d", &u, &v);
        int res = lca(u, v);
        printf("%d\n", dis[u] + dis[v] - 2 * dis[res]);
    }
    return 0;
}