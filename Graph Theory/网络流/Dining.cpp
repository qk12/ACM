// POJ 3281
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
const int INF = 0x3f3f3f3f;
const int max_v = 505;
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    int d[max_v];
    int cur[max_v];
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool bfs()
    {
        memset(vis, 0, sizeof(vis)), memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(s);
        d[s] = 0, vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int max_flow(int s, int t)
    {
        this->s = s, this->t = t;
        int flow = 0;
        while (bfs())
        {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        return flow;
    }
};

Dinic D;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, f, d;
    cin >> n >> f >> d;
    D.init(f + 2 * n + d + 2);
    int x, y, z;
    int s = f + 2 * n + d;
    int t = s + 1;
    for (int i = 0; i < f; ++i)
        D.AddEdge(s, 2 * n + i, 1);
    for (int i = 0; i < d; ++i)
        D.AddEdge(2 * n + f + i, t, 1);
    for (int i = 0; i < n; ++i)
    {
        D.AddEdge(i, i + n, 1);
        cin >> x >> y;
        while (x--)
        {
            cin >> z;
            D.AddEdge(2 * n + z - 1, i, 1);
        }
        while (y--)
        {
            cin >> z;
            D.AddEdge(i + n, 2 * n + f + z - 1, 1);
        }
    }
    cout << D.max_flow(s, t) << endl;
    return 0;
}