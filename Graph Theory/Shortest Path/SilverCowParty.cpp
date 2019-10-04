// POJ 3268
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 1005;
int ans[max_v];
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
    vector<int> G[max_v];
    bool done[max_v];
    int dis[max_v];
    int p[max_v];
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
            ans[i] += dis[i];
    }
};

const int maxm = 1e5 + 5;
int u[maxm], v[maxm], w[maxm];
Dijkstra D;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    while (cin >> n >> m >> x)
    {
        D.init(n);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < m; ++i)
        {
            cin >> u[i] >> v[i] >> w[i];
            D.AddEdge(u[i] - 1, v[i] - 1, w[i]);
        }
        D.dijkstra(x - 1);
        D.init(n);
        for (int i = 0; i < m; ++i)
            D.AddEdge(v[i] - 1, u[i] - 1, w[i]);
        D.dijkstra(x - 1);
        cout << *max_element(ans, ans + n) << endl;
    }
    return 0;
}