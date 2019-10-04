// POJ 1511
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 1000005;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    int dist, u;
    bool operator<(const HeapNode &rhs) const
    {
        return dist > rhs.dist;
    }
};
vector<Edge> edges;
vector<int> G[max_v];
bool done[max_v];
int dis[max_v];
int p[max_v];
int from[max_v], to[max_v], dist[max_v];
long long ans;
struct Dijkstra
{
    int n, m;
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < V; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge{from, to, dist});
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; ++i)
            dis[i] = INF;
        dis[s] = 0;
        memset(done, 0, sizeof(done));
        q.push({0, s});
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u])
                continue;
            done[u] = true;
            for (int id = 0; id < G[u].size(); ++id)
            {
                Edge &e = edges[G[u][id]];
                if (dis[e.to] > dis[u] + e.dist)
                {
                    dis[e.to] = dis[u] + e.dist;
                    p[e.to] = G[u][id];
                    q.push({dis[e.to], e.to});
                }
            }
        }
        for (int i = 0; i < n; ++i)
            ans += dis[i];
    }
};

Dijkstra D;
int main()
{
    int T;
    scanf("%d", &T);
    int V, E;
    while(T--)
    {
        ans = 0;
        scanf("%d%d", &V, &E);
        D.init(V);
        for (int j = 0; j < E; ++j)
        {
            scanf("%d%d%d", &from[j], &to[j], &dist[j]);
            D.AddEdge(from[j] - 1, to[j] - 1, dist[j]);
        }
        D.dijkstra(0);
        D.init(V);
        for (int j = 0; j < E; ++j)
            D.AddEdge(to[j] - 1, from[j] - 1, dist[j]);
        D.dijkstra(0);
        printf("%lld\n", ans);
    }
    return 0;
}
