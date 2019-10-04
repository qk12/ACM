// POJ 2135
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};
typedef long long ll;
const int max_v=1005;
const int INF=0x3f3f3f;
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    int inq[max_v];
    int d[max_v];   
    int p[max_v];   
    int a[max_v];   
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellmanFord(int s, int t, int &flow, ll &cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        queue<int> q;
        q.push(s);
        d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF)
            return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    int MincostMaxflow(int s, int t, ll &cost)
    {
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    MCMF M;
    M.init(n+2);
    int s=n,t=n+1;
    M.AddEdge(s,0,2,0);
    M.AddEdge(n-1,t,2,0);
    int x,y,z;
    while(m--)
    {
        cin>>x>>y>>z;
        M.AddEdge(x-1,y-1,1,z);
    }
    ll cost;
    M.MincostMaxflow(s,t,cost);
    cout<<cost<<endl;
    return 0;
}