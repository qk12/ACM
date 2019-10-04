// POJ 2031
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int max_v = 105;
double x[max_v], y[max_v], z[max_v], r[max_v];
struct Prim
{
    int V;                     //顶点数
    double cost[max_v][max_v]; //cost[u][v]表示边e={u,v}的权值（不存在的设为INF，已存在的设为0）
    double dis[max_v];         //从集合X出发的边到每个顶点的最小权值
    bool vis[max_v];           //顶点i是否包含在集合X中
    void init(int V)           //顶点从0开始编号，若题目从1开始编号，则输入时要减一
    {
        this->V = V;
        for (int i = 0; i < V; ++i)
            dis[i] = 1e9, vis[i] = false;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                cost[i][j] = 1e9;
    }
    double prim()
    {
        dis[0] = 0;
        double res = 0;
        while (true)
        {
            int v = -1;
            for (int u = 0; u < V; ++u) //从不属于X的顶点中选取从X到其权值最小的顶点
                if (!vis[u] && (v == -1 || dis[u] < dis[v]))
                    v = u;
            if (v == -1)
                break;
            vis[v] = true; //把顶点v加入X
            res += dis[v]; //把边的长度加到结果里
            for (int u = 0; u < V; ++u)
                dis[u] = min(dis[u], cost[v][u]);
        }
        return res;
    }
};

int main()
{
    int V;
    while (cin >> V, V)
    {
        Prim P;
        P.init(V);
        for (int i = 0; i < V; ++i)
        {
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }
        for (int i = 0; i < V - 1; ++i)
            for (int j = i + 1; j < V; ++j)
            {
                double dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j])) - r[i] - r[j];
                if (dis <= 0)
                    P.cost[i][j] = P.cost[j][i] = 0;
                else
                    P.cost[i][j] = P.cost[j][i] = dis;
            }
        printf("%.3f\n", P.prim());
    }
    return 0;
}