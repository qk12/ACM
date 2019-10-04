// Luogu 1346
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 10005;

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
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int dis[maxn];
    int p[maxn];
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < V; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++)
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
            for (auto &id : G[u])
            {
                Edge &e = edges[id];
                if (dis[e.to] > dis[u] + e.dist)
                {
                    dis[e.to] = dis[u] + e.dist;
                    p[e.to] = id;
                    q.push({dis[e.to], e.to});
                }
            }
        }
    }
};

int main()
{
    Dijkstra D;
    int V, S, F;
    cin >> V >> S >> F;
    D.init(V);
    int E, to;
    for (int i = 0; i < V; ++i)
    {
        cin >> E;
        for (int j = 0; j < E; ++j)
        {
            cin >> to;
            if (j == 0)
                D.AddEdge(i, to - 1, 0);
            else
                D.AddEdge(i, to - 1, 1);
        }
    }
    D.dijkstra(S - 1);
    cout << (D.dis[F - 1] == INF ? -1 : D.dis[F - 1]) << endl;
    return 0;
}
