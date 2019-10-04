// POJ 2226
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int max_v = 1005;
vector<int> G[max_v];
int linker[max_v];
bool vis[max_v];
int id1 = 0, id2 = 0;
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

char map[max_v][max_v];
int m1[max_v][max_v], m2[max_v][max_v];
int n, m;
void build()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '*')
            {
                while (map[i][j] == '*')
                {
                    m1[i][j] = id1;
                    ++j;
                }
                ++id1;
            }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (map[i][j] == '*')
            {
                while (map[i][j] == '*')
                {
                    m2[i][j] = id2;
                    ++i;
                }
                ++id2;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '*')
                addedge(m1[i][j], m2[i][j]);
}

int main()
{
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> map[i][j];
    build();
    printf("%d\n", hungary(id1));
    return 0;
}