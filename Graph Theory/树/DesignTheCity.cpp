// ZOJ 3195
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int to, w;
    edge() {}
    edge(int v, int d) : to(v), w(d) {}
};

typedef pair<int, int> PII;
const int maxn = 5e4 + 5;
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
    for (int i = 0; i < (int)G[u].size(); ++i)
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
        dp[0][i] = PII(dfn[sp[i]], sp[i]);
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
    for (int i = 0; i < (int)G[u].size(); ++i)
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
    bool flag = true;
    while (scanf("%d", &n) != EOF)
    {
        if (flag)
            flag = false;
        else
            printf("\n");
        init(n);
        memset(dis, 0, sizeof(dis));
        int x, y, w;
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d%d%d", &x, &y, &w);
            G[x].push_back(edge(y, w));
            G[y].push_back(edge(x, w));
        }
        dfs2(0, -1, 0);
        dfs(0, -1);
        initrmq();
        scanf("%d", &m);
        int a, b, c;
        while (m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            int ans = dis[a] + dis[b] + dis[c] - (dis[lca(a, b)] + dis[lca(a, c)] + dis[lca(b, c)]);
            printf("%d\n", ans);
        }
    }
    return 0;
}