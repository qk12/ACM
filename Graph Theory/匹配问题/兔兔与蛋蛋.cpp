// HYSBZ 2437
#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;
const int INF = 0x3f3f3f3f;
int n, m;
int cost[maxn][maxn];
int lx[maxn], ly[maxn], match[maxn], slack[maxn];
int pre[maxn];
bool vy[maxn];
void augment(int root)
{
    fill(vy + 1, vy + n + 1, false);
    fill(slack + 1, slack + n + 1, INF);
    int py;
    match[py = 0] = root;
    do
    {
        vy[py] = true;
        int x = match[py], yy;
        int delta = INF;
        for (int y = 1; y <= n; y++)
        {
            if (!vy[y])
            {
                if (lx[x] + ly[y] - cost[x][y] < slack[y])
                    slack[y] = lx[x] + ly[y] - cost[x][y], pre[y] = py;
                if (slack[y] < delta)
                    delta = slack[y], yy = y;
            }
        }
        for (int y = 0; y <= n; y++)
        {
            if (vy[y])
                lx[match[y]] -= delta, ly[y] += delta;
            else
                slack[y] -= delta;
        }
        py = yy;
    } while (match[py] != -1);
    do
    {
        int temp = pre[py];
        match[py] = match[temp], py = temp;
    } while (py);
}
int KM()
{
    for (int i = 1; i <= n; i++)
    {
        lx[i] = ly[i] = 0;
        match[i] = -1;
        for (int j = 1; j <= n; j++)
            lx[i] = max(lx[i], cost[i][j]);
    }
    int res = 0;
    for (int root = 1; root <= n; root++)
        augment(root);
    for (int i = 1; i <= n; i++)
        res += lx[i], res += ly[i];
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    int u, v, w;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cost[i][j] = -INF;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            cost[u][v] = max(cost[u][v], -w);
        }
        printf("%d\n", -KM());
    }
    return 0;
}