// HDU 3974
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
const int maxn = 50005;
vector<int> G[maxn];
int deg[maxn];
int in[maxn], out[maxn]; //进出栈的时间序列
int val[maxn << 2];
int dfs_clock;

void init(int n)
{
    dfs_clock = 0;
    clr(deg, 0);
    for (int i = 1; i <= n; ++i)
        G[i].clear();
}
void add_edge(int u, int v) { G[v].push_back(u), ++deg[u]; }
void dfs(int u)
{
    in[u] = ++dfs_clock;
    for (auto &v : G[u])
        dfs(v);
    out[u] = dfs_clock;
}

void build(int l, int r, int rt)
{
    val[rt] = -1;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}
void pushdown(int rt)
{
    if (val[rt] == -1)
        return;
    val[lson] = val[rson] = val[rt];
    val[rt] = -1;
}
void update(int L, int R, int setv, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] = setv;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, setv, Lson);
    if (m < R)
        update(L, R, setv, Rson);
}
int query(int p, int l, int r, int rt)
{
    if (l == r)
        return val[rt];
    pushdown(rt);
    int m = (l + r) >> 1;
    if (p <= m)
        return query(p, Lson);
    else
        return query(p, Rson);
}

int main()
{
    int T;
    scanf("%d", &T);
    int n, m, x, y;
    char c[5];
    int u, v;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d", &n);
        init(n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
            {
                dfs(i);
                break;
            }
        int N = dfs_clock;
        build(1, N, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", k);
        while (m--)
        {
            scanf("%s", c);
            if (c[0] == 'T')
            {
                scanf("%d%d", &x, &y);
                update(in[x], out[x], y, 1, N, 1);
            }
            else
            {
                scanf("%d", &x);
                printf("%d\n", query(in[x], 1, N, 1));
            }
        }
    }
    return 0;
}