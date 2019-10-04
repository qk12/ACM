// POJ 2289
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
int n, m;
int G[maxn][maxn];
int linker[maxn][maxn];
bool vis[maxn];
bool dfs(int u, int limit)
{
    for (int v = 0; v < m; ++v)
        if (G[u][v] && !vis[v])
        {
            vis[v] = true;
            if (linker[v][0] < limit)
            {
                linker[v][++linker[v][0]] = u;
                return true;
            }
            for (int i = 1; i <= limit; ++i)
                if (dfs(linker[v][i], limit))
                {
                    linker[v][i] = u;
                    return true;
                }
        }
    return false;
}
bool hungary(int limit)
{
    memset(linker, 0, sizeof(linker));
    for (int u = 0; u < n; ++u)
    {
        memset(vis, 0, sizeof(vis));
        if (!dfs(u, limit))
            return false;
    }
    return true;
}
int solve()
{
    int L = 1, R = n;
    while (L < R)
    {
        int mid = L + (R - L) / 2;
        if (!hungary(mid))
            L = mid + 1;
        else
            R = mid;
    }
    return L;
}

int main()
{
    int x;
    char s[20], ch;
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 || m == 0)
            break;
        memset(G, 0, sizeof(G));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            while (true)
            {
                scanf("%d%c", &x, &ch);
                G[i][x] = 1;
                if (ch == '\n')
                    break;
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}