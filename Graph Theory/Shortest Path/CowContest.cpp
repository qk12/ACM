// POJ 3660
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 105;
bool G[maxn][maxn];

void floyd(int n)
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] |= G[i][k] & G[k][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int u, v;
    while (cin >> n >> m)
    {
        memset(G, 0, sizeof(G));
        while (m--)
        {
            cin >> u >> v;
            G[u - 1][v - 1] = true;
        }
        floyd(n);
        int cnt = 0;
        //若某一个顶点与其余n-1个顶点都有关系，则其排名是确定的
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (G[i][j] | G[j][i])
                    ++tmp;
            if (tmp == n - 1)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}