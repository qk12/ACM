// POJ 1502
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 105;
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
    }
};

int getdis(char *s)
{
    int res = 0, n = strlen(s);
    for (int i = 0; i < n; ++i)
        res = res * 10 + s[i] - '0';
    return res;
}
Dijkstra D;
char s[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        D.init(n);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
            {
                cin >> s;
                if (s[0] == 'x')
                    continue;
                int d = getdis(s);
                D.AddEdge(i, j, d);
                D.AddEdge(j, i, d);
            }
        D.dijkstra(0);
        cout << *max_element(D.dis, D.dis + n) << endl;
    }
    return 0;
}
