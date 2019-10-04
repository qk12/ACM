// POJ 2516
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int max_v = 105;
const int maxm = 55;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    int inq[max_v]; //是否在队列中
    int d[max_v];   //bellmanford
    int p[max_v];   //上一条弧
    int a[max_v];   //可改进量
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

MCMF ans;
int need[maxm], supply[maxm], to[maxm][maxm], from[maxm][maxm];
int cost[maxm][maxm][maxm];

bool check(int k)
{
    for (int i = 0; i < k; i++)
        if (need[i] > supply[i])
            return false;
    return true;
}

int main()
{
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k), n + m + k)
    {
        clr(supply, 0);
        clr(need, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &to[i][j]);
                need[j] += to[i][j];
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &from[i][j]);
                supply[j] += from[i][j];
            }
        for (int p = 0; p < k; ++p)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    scanf("%d", &cost[p][i][j]);
        if (!check(k)) //供不应求
        {
            printf("-1\n");
            continue;
        }
        int s = n + m, t = s + 1;
        ll res = 0;
        for (int p = 0; p < k; p++)
        {
            ans.init(t + 1);
            for (int i = 0; i < m; i++)
                ans.AddEdge(s, i, from[i][p], 0);
            for (int i = 0; i < n; i++)
            {
                ans.AddEdge(m + i, t, to[i][p], 0);
                for (int j = 0; j < m; j++)
                    ans.AddEdge(j, m + i, INF, cost[p][i][j]);
            }
            ll cost;
            ans.MincostMaxflow(s, t, cost);
            res += cost;
        }
        printf("%lld\n", res);
    }
    return 0;
}
