// Luogu 3387
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int a[maxn], sccval[maxn], dp[maxn];
vector<int> SCC[maxn];
vector<int> G[maxn];
int dfn[maxn];
int lowlink[maxn];
int idx[maxn];
int id, scc_cnt;
stack<int> S;
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
inline void addedge(int u, int v) { G[u].push_back(v); }
void dfs(int u)
{
    dfn[u] = lowlink[u] = ++id;
    S.push(u);
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!idx[v])
            lowlink[u] = min(lowlink[u], dfn[v]);
    }
    if (lowlink[u] == dfn[u])
    {
        ++scc_cnt;
        while (true)
        {
            int x = S.top();
            S.pop();
            idx[x] = scc_cnt;
            sccval[scc_cnt] += a[x];
            if (x == u)
                break;
        }
    }
}
int tarjan(int n)
{
    id = 0, scc_cnt = 0;
    memset(idx, 0, sizeof(idx)), memset(dfn, 0, sizeof(dfn));
    for (int i = 0; i < n; i++)
        if (!dfn[i])
            dfs(i);
    return scc_cnt;
}
int solve(int u)
{
    if (dp[u])
        return dp[u]; //若访问过，直接返回调用
    int res = 0;      //取相邻点最大值用
    for (auto &v : SCC[u])
    {
        if (!dp[v])
            solve(v);          //没访问过就深搜
        res = max(res, dp[v]); //选取最大值
    }
    return dp[u] = res + sccval[u];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int from, to;
    while (m--)
    {
        scanf("%d%d", &from, &to);
        addedge(from - 1, to - 1);
    }
    int res = tarjan(n);
    for (int u = 0; u < n; ++u)
        for (auto &v : G[u])
            if (idx[u] != idx[v])
                SCC[idx[u]].push_back(idx[v]); //缩点，多条重复路径的影响可以忽略不计，对DP没有影响
    for (int i = 1; i <= res; ++i)
        if (!dp[i])
            solve(i);
    int ans = 0;
    for (int i = 1; i <= res; ++i)
        ans = max(ans, dp[i]); //寻找所有SCC中最大的 f 值
    printf("%d\n", ans);
    return 0;
}