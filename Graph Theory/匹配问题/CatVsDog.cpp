// HDU 3829
#include <bits/stdc++.h>
using namespace std;

const int max_v = 1005;
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

int main()
{
    int n, m, p;
    string s1[1005], s2[1005];
    while (scanf("%d%d%d", &n, &m, &p) != EOF)
    {
        init(p);
        for (int i = 0; i < p; ++i)
            cin >> s1[i] >> s2[i];
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                if (s1[i] == s2[j] || s2[i] == s1[j])
                    addedge(i, j);
        printf("%d\n", p - hungary(p) / 2);
    }
    return 0;
}