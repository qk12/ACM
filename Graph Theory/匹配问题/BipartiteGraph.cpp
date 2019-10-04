// HDU 5313
#include <bits/stdc++.h>
using namespace std;

const int max_v = 505;
vector<int> G[max_v];
int linker[max_v];
bool vis[max_v];
inline void init(int n)
{
    for (int i = 0; i < n; ++i)
        G[i].clear();
}
inline void addedge(int u, int v) { G[u].push_back(v); }
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(int n)
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int i = 0; i < n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            ++res;
    }
    return res;
}

int w[max_v], l[max_v], h[max_v];

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        init(n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d%d", &w[i], &l[i], &h[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (w[i] < w[j] && l[i] < l[j] && h[i] < h[j])
                    addedge(i, j);
            }
        printf("%d\n", n - hungary(n));
    }
    return 0;
}