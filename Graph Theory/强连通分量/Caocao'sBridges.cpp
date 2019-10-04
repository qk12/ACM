// HDU 4738
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int cost[maxn][maxn];
int pre[maxn], lowlink[maxn];
bool vis[maxn];
int idx;
int cnt;
int ans;
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
inline void add_edge(int u, int v) { G[u].push_back(v); }
void dfs(int u, int father)
{
    pre[u] = lowlink[u] = ++idx;
    bool flag = true;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (v == father && flag) // 重边判断，只需过滤一次
        {
            flag = false;
            continue;
        }
        if (!pre[v])
            dfs(v, u);
        lowlink[u] = min(lowlink[u], lowlink[v]);
        if (lowlink[v] > pre[u])
        {
            ans = min(ans, cost[u][v]);
            ++cnt;
        }
    }
}
void tarjan(int n)
{
    idx = 0;
    memset(pre, 0, sizeof(pre)), memset(vis, 0, sizeof(vis));
    dfs(1, -1);
}

int main()
{
    int n, m;
    int u, v, w;
    while (scanf("%d%d", &n, &m) == 2 && n && m)
    {
        init(n);
        cnt = 0;
        ans = INF;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v);
            add_edge(v, u);
            cost[u][v] = cost[v][u] = w;
        }
        tarjan(n);
        if (ans == 0) // “桥”上士兵为0，至少派一个人去炸桥
            printf("1\n");
        else
            printf("%d\n", (ans == INF) ? -1 : ans); // ans = inf 说明计划失败
    }
    return 0;
}
