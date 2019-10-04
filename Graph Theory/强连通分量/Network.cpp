// POJ 1144
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 105;
vector<int> G[maxn];
int dfn[maxn], lowlink[maxn];
bool vis[maxn];
int idx;
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
inline void addedge(int u, int v) { G[u].push_back(v); }
void dfs(int u, int father)
{
    dfn[u] = lowlink[u] = ++idx;
    int child = 0;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            dfs(v, u);
            lowlink[u] = min(lowlink[u], lowlink[v]);
            if (lowlink[v] >= dfn[u] && u != father)
                vis[u] = true;
            if (u == father)
                ++child;
        }
        lowlink[u] = min(lowlink[u], dfn[v]);
    }
    if (child >= 2 && u == father)
        vis[u] = true;
}
int tarjan(int n)
{
    idx = 0;
    memset(dfn, 0, sizeof(dfn)), memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!dfn[i])
            dfs(i, i);
    int res = 0;
    for (int i = 0; i < n; ++i)
        if (vis[i])
            ++res;
    return res;
}

int main()
{
    int n;
    int from, to;
    char ch;
    while (scanf("%d", &n), n)
    {
        init(n);
        while (scanf("%d", &from), from)
        {
            while (scanf("%c", &ch), ch != '\n')
            {
                scanf("%d", &to);
                addedge(from - 1, to - 1);
                addedge(to - 1, from - 1);
            }
        }
        printf("%d\n", tarjan(n));
    }
    return 0;
}