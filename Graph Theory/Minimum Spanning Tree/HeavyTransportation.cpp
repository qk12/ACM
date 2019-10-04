// POJ 1797
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int max_v = 1005;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
bool cmp(const Edge &e1, const Edge &e2) { return e1.dist > e2.dist; }
struct Kruskal
{
    int V;
    int father[max_v];
    vector<Edge> edges;
    void init(int V)
    {
        this->V = V;
        for (int i = 0; i < V; ++i)
            father[i] = i;
        edges.clear();
    }
    int find(int x)
    {
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        father[x] = y;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge{from, to, dist});
    }
    int kruskal()
    {
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < edges.size(); ++i)
        {
            Edge &e = edges[i];
            unite(e.from, e.to);
            if (same(0, V - 1))
                return e.dist;
        }
        return -1;
    }
};

Kruskal K;
int main()
{
    int T;
    scanf("%d", &T);
    int V, E;
    int from, to, dist;
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d%d", &V, &E);
        K.init(V);
        while (E--)
        {
            scanf("%d%d%d", &from, &to, &dist);
            K.AddEdge(from - 1, to - 1, dist);
            K.AddEdge(to - 1, from - 1, dist);
        }
        printf("Scenario #%d:\n", i);
        printf("%d\n", K.kruskal());
        printf("\n");
    }
    return 0;
}