// POJ 1789
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 2005;
int cost[max_v][max_v];
struct Prim
{
    int V;
    int dis[max_v];
    bool vis[max_v];
    void init(int V)
    {
        this->V = V;
        for (int i = 0; i < V; ++i)
            dis[i] = INF, vis[i] = false;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                cost[i][j] = INF;
    }
    int prim()
    {
        dis[0] = 0;
        int res = 0;
        while (true)
        {
            int v = -1;
            for (int u = 0; u < V; ++u)
                if (!vis[u] && (v == -1 || dis[u] < dis[v]))
                    v = u;
            if (v == -1)
                break;
            vis[v] = true;
            res += dis[v];
            for (int u = 0; u < V; ++u)
                dis[u] = min(dis[u], cost[v][u]);
        }
        return res;
    }
};

char str[max_v][10];
int getdist(int i, int j)
{
    int res = 0;
    for (int k = 0; k < 7; k++)
        if (str[i][k] != str[j][k])
            ++res;
    return res;
}

Prim P;
int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        P.init(n);
        for (int i = 0; i < n; ++i)
            scanf("%s", str[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cost[i][j] = getdist(i, j);
        printf("The highest possible quality is 1/%d.\n", P.prim());
    }
    return 0;
}
