// POJ 3321
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
int bit[maxn];
int in[maxn], out[maxn];
int n, dfs_clock;
vector<vector<int>> G(maxn);

inline int lowbit(int x) { return x & -x; }
void add(int pos, int x)
{
    while (pos <= n)
        bit[pos] += x, pos += lowbit(pos);
}
int sum(int pos) //[x,y]: sum(y) - sum(x - 1);
{
    int res = 0;
    while (pos > 0)
        res += bit[pos], pos -= lowbit(pos);
    return res;
}

void dfs(int u)
{
    in[u] = ++dfs_clock;
    for (int i = 0; i < G[u].size(); i++)
        dfs(G[u][i]);
    out[u] = dfs_clock;
}

bool vis[maxn];
int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 1;
        add(in[i], 1);
    }
    int m, x;
    char s[2];
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s%d", s, &x);
        if (s[0] == 'Q')
            printf("%d\n", sum(out[x]) - sum(in[x] - 1));
        else
        {
            if (vis[x])
                add(in[x], -1);
            else
                add(in[x], 1);
            vis[x] = !vis[x];
        }
    }
    return 0;
}
