#include <bits/stdc++.h>
using namespace std;

const int max_v = 0;
const int INF = 0;
struct edge //用于表示边的结构体（终点、容量、反向边）
{
    int to, cap, rev;
};
vector<edge> G[max_v]; //图的邻接表表示
bool vis[max_v];       //DFS中用到的访问标记
void add_edge(int from, int to, int cap) //从图中增加一条从s到t的容量为cap的边
{
    G[from].push_back(edge{
        to, cap, (int)G[to].size()});
    G[to].push_back(edge{
        from, 0, (int)G[from].size() - 1});
}
int dfs(int v, int t, int f) //通过DFS寻找增广路
{
    if (v == t)
        return f;
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if (!vis[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) //求解从s到t的最大流
{
    int flow = 0;
    for (;;)
    {
        memset(vis, false, sizeof(vis));
        int f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}