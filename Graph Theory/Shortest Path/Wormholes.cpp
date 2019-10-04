// POJ 3259
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 505;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct BellmanFord
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool inq[max_v];
    int dis[max_v];
    int p[max_v];
    int cnt[max_v];
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
    bool bellmanford(int s)
    {
        queue<int> q;
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
            dis[i] = INF;
        dis[s] = 0;
        inq[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id = 0; id < G[u].size(); ++id)
            {
                Edge &e = edges[G[u][id]];
                if (dis[u] < INF && dis[e.to] > dis[u] + e.dist)
                {
                    dis[e.to] = dis[u] + e.dist;
                    p[e.to] = G[u][id];
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = true;
                        if (++cnt[e.to] > n)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int V, E, W;
    int from, to, dist;
    while (T--)
    {
        cin >> V >> E >> W;
        BellmanFord B;
        B.init(V);
        while (E--)
        {
            cin >> from >> to >> dist;
            B.AddEdge(from - 1, to - 1, dist);
            B.AddEdge(to - 1, from - 1, dist);
        }
        while (W--)
        {
            cin >> from >> to >> dist;
            B.AddEdge(from - 1, to - 1, -1 * dist);
        }
        if (B.bellmanford(0))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}