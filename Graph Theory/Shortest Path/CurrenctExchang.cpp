// POJ 1860
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 105;
bool G[maxn][maxn];
double d[maxn];
double r[maxn][maxn], c[maxn][maxn];

bool bfs(int s, double v, int n)
{
    queue<int> q;
    d[s] = v;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == s && d[u] > v)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (G[u][i])
            {
                double tmp = (d[u] - c[u][i]) * r[u][i];
                if (tmp > d[i])
                {
                    d[i] = tmp;
                    q.push(i);
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s;
    double v;
    while (cin >> n >> m >> s >> v)
    {
        memset(G, 0, sizeof(G));
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            cin >> r[u - 1][v - 1] >> c[u - 1][v - 1];
            cin >> r[v - 1][u - 1] >> c[v - 1][u - 1];
            G[u - 1][v - 1] = G[v - 1][u - 1] = true;
        }
        if (bfs(s - 1, v, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}