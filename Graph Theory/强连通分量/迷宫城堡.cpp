// HDU 1269
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
vector<int> G[maxn];
int pre[maxn];
int lowlink[maxn];
int id[maxn];
int idx, scc_cnt;
stack<int> S;
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
inline void add_edge(int u, int v) { G[u].push_back(v); }
void dfs(int u)
{
    pre[u] = lowlink[u] = ++idx;
    S.push(u);
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!id[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        ++scc_cnt;
        while (true)
        {
            int x = S.top();
            S.pop();
            id[x] = scc_cnt;
            if (x == u)
                break;
        }
    }
}
int tarjan(int n)
{
    idx = 0, scc_cnt = 0;
    memset(id, 0, sizeof(id)), memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i);
    return scc_cnt;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        init(n);
        int from, to;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &from, &to);
            add_edge(from - 1, to - 1);
        }
        int ans = tarjan(n);
        if (ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
