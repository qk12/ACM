// HDU 1281
#include <cstring>
#include <iostream>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))

const int maxn = 105;
int uN, vN, k;
int g[maxn][maxn];
int linker[maxn], save[maxn];
bool vis[maxn];
bool dfs(int u)
{
    for (int v = 0; v < vN; ++v)
        if (g[u][v] && !vis[v])
        {
            vis[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary(int uN)
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(u))
            ++res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while (cin >> uN >> vN >> k)
    {
        clr(g, 0);
        int a, b;
        while (k--)
        {
            cin >> a >> b;
            g[a - 1][b - 1] = 1;
        }
        int ans = hungary(uN);
        int cnt = 0;
        for (int i = 0; i < vN; i++)
            save[i] = linker[i];
        for (int i = 0; i < vN; i++)
        {
            for (int j = 0; j < vN; j++)
                linker[j] = save[j];
            if (linker[i] != -1)
            {
                int tmp = linker[i];
                g[tmp][i] = 0, linker[i] = -1;
                clr(vis, 0);
                if (!dfs(tmp))
                    ++cnt;
                g[tmp][i] = 1;
            }
        }
        cout << "Board " << ++kase << " have " << cnt << " important blanks for " << ans << " chessmen." << endl;
    }
    return 0;
}
