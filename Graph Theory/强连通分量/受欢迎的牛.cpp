// Luogu 2341
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
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

int cnt[maxn];
int out[maxn];

int main()
{
    int n, m;
    int from, to;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &from, &to);
        addedge(from - 1, to - 1);
    }
    memset(out, 0, sizeof(out));
    int res = tarjan(n);
    for (int u = 0; u < n; ++u)
    {
        ++cnt[idx[u]];
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (idx[u] != idx[v])
            {
                ++out[idx[u]];
            }
        }
    }
    int ans = 0;
    int anscnt = 0;
    for (int i = 1; i <= res; ++i)
    {
        if (out[i] == 0)
        {
            ++anscnt;
            ans += cnt[i];
        }
    }
    if (anscnt >= 2)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}