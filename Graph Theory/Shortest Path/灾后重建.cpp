// POJ 1119
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 205;
int V, E;
int a[maxn], dis[maxn][maxn];

void updata(int k)
{
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); //用这个新的更新所有前面的
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        cin >> a[i]; //依次输入每一个村庄建立完成时需要的时间
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (i != j)
                dis[i][j] = INF; //初始化为保证它不爆炸范围内的最大值
    int from, to, dist;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> dist;
        dis[from][to] = dis[to][from] = dist; //初始化边长
    }
    int Q;
    cin >> Q;
    int now = 0, t;
    while (Q--) //处理各询问
    {
        cin >> from >> to >> t;
        while (a[now] <= t && now < V)
        {
            updata(now); //依次更新点，使它可以被用来更新其他的点
            ++now;
        }
        if (a[from] > t || a[to] > t)
            cout << -1 << endl;
        else
            cout << (dis[from][to] == INF ? -1 : dis[from][to]) << endl;
    }
    return 0;
}