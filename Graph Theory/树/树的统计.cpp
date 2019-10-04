// HYSBZ 1036
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 30005;
// Segment Tree
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
int val[maxn];
int sumv[maxn << 2], maxv[maxn << 2];
inline void pushup(int rt)
{
    sumv[rt] = sumv[lson] + sumv[rson];
    maxv[rt] = max(maxv[lson], maxv[rson]);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        sumv[rt] = maxv[rt] = val[l];
        return;
    }
    int m = (l + r) >> 1;
    build(Lson), build(Rson);
    pushup(rt);
}
void update(int p, int v, int l, int r, int rt)
{
    if (l == r)
    {
        sumv[rt] = maxv[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    pushup(rt);
}
int query_max(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return maxv[rt];
    int m = (l + r) >> 1, res = -INF;
    if (L <= m)
        res = max(res, query_max(L, R, Lson));
    if (m < R)
        res = max(res, query_max(L, R, Rson));
    return res;
}
int query_sum(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sumv[rt];
    int m = (l + r) >> 1, res = 0;
    if (L <= m)
        res += query_sum(L, R, Lson);
    if (m < R)
        res += query_sum(L, R, Rson);
    return res;
}

struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n, clr(son, -1), dfs_clock = 0;
        for (int i = 0; i <= n; i++)
            G[i].clear();
    }
    void add_edge(int u, int v) { G[u].pb(v), G[v].pb(u); }
    void dfs(int u, int p, int d)
    {
        dep[u] = d, fa[u] = p, sz[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (v == p)
                continue;
            dfs(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]])
                son[u] = v;
        }
    }
    void link(int u, int t)
    {
        top[u] = t, id[u] = ++dfs_clock;
        if (son[u] == -1)
            return;
        link(son[u], t);
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (v != son[u] && v != fa[u])
                link(v, v);
        }
    }
    void getval()
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[id[i]]);
    }
    void update(int u, int v) { ::update(id[u], v, 1, n, 1); }
    int query_max(int u, int v)
    {
        int res = -INF;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            res = max(res, ::query_max(id[top[u]], id[u], 1, n, 1));
            u = fa[top[u]];
        }
        if (dep[u] > dep[v])
            swap(u, v);
        res = max(res, ::query_max(id[u], id[v], 1, n, 1));
        return res;
    }
    int query_sum(int u, int v)
    {
        int res = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            res += ::query_sum(id[top[u]], id[u], 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v])
            swap(u, v);
        res += ::query_sum(id[u], id[v], 1, n, 1);
        return res;
    }
} T;

int main()
{
    int n;
    scanf("%d", &n);
    T.init(n);
    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        T.add_edge(u, v);
    }
    T.dfs(1, 1, 1);
    T.link(1, 1);
    T.getval();
    build(1, n, 1);
    int m;
    scanf("%d", &m);
    char op[10];
    while (m--)
    {
        static int u, v;
        scanf("%s%d%d", op, &u, &v);
        if (op[1] == 'H')
            T.update(u, v);
        if (op[1] == 'M')
            printf("%d\n", T.query_max(u, v));
        if (op[1] == 'S')
            printf("%d\n", T.query_sum(u, v));
    }
    return 0;
}
