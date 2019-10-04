// POJ 2631
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Edge
{
    int to, w;
};

const int maxn = 1e4 + 5;
vector<Edge> G[maxn];
int dis[maxn];

void dfs(int u, int fa, int dist)
{
    dis[u] = dist;
    for (int i = 0; i < G[u].size(); ++i)
    {
        Edge it = G[u][i];
        int v = it.to, w = it.w;
        if (v != fa)
            dfs(v, u, dist + w);
    }
}

int main()
{
    int u, v, w;
    int n = 0;
    while (scanf("%d%d%d", &u, &v, &w) != EOF)
    {
        n = max(n, max(u, v));
        G[u].push_back(Edge{v, w});
        G[v].push_back(Edge{u, w});
    }
    dfs(1, -1, 0);
    int maxx = 0;
    int id = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dis[i] > maxx)
        {
            id = i, maxx = dis[i];
        }
    }
    dfs(id, -1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dis[i]);
    }
    printf("%d\n", ans);
    return 0;
}