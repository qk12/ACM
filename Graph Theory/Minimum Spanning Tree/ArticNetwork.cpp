// POJ 2349
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int max_v = 505;
double ans[max_v];
struct Edge
{
    int from, to;
    double dist;
    Edge() {}
    Edge(int u, int v, double d) : from(u), to(v), dist(d) {}
};
bool cmp(const Edge &e1, const Edge &e2) { return e1.dist < e2.dist; }
struct Kruskal
{
    int n; //顶点数，边数
    int father[max_v];
    vector<Edge> edges;
    void init(int V) //初始化
    {
        this->n = V;
        for (int i = 0; i < n; ++i) //顶点从0开始编号，若题目从1开始编号，则输入时要减一
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
    void AddEdge(int from, int to, double dist) //无向图需调用两次
    {
        edges.push_back(Edge{from, to, dist});
    }
    int kruskal() //不存在最小生成树时返回-1
    {
        sort(edges.begin(), edges.end(), cmp); //按照edge.cost的顺序从小到大排列
        int res = 0, cnt = 0;
        for (int i = 0; i < edges.size(); ++i)
        {
            Edge &e = edges[i];
            if (!same(e.from, e.to))
            {
                unite(e.from, e.to);
                ++cnt;
                res += e.dist; //res = sum/max/min(res,e.dist);
                ans[cnt] = e.dist;
            }
        }
        return cnt == n - 1 ? res : -1; //最小生成树的边必为顶点数减一
    }
};

int x[max_v], y[max_v];
Kruskal K;
double dis(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main()
{
    int T;
    scanf("%d", &T);
    int s, p;
    while (T--)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d%d", &s, &p);
        K.init(p);
        for (int i = 0; i < p; ++i)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i < p; ++i)
            for (int j = i + 1; j < p; ++j)
            {
                double d = dis(i, j);
                K.AddEdge(i, j, d);
                K.AddEdge(j, i, d);
            }
        K.kruskal();
        printf("%.2f\n", ans[p - s]);
    }
    return 0;
}