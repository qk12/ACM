// Mayor's posters, POJ2528
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

typedef pair<int, int> P;
const int maxn = 2e4 + 5;
P a[maxn];
vector<int> v;
int val[maxn << 2];
bool vis[maxn];

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
void update(int x, int y, int setv, int l, int r, int rt)
{
    if (x <= l && y >= r)
    {
        val[rt] = setv;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, y, setv, Lson);
    if (y > m)
        update(x, y, setv, Rson);
}
int query(int x, int l, int r, int rt)
{
    if (l == r)
        return val[rt];
    pushdown(rt);
    int m = (l + r) >> 1;
    if (x <= m)
        return query(x, Lson);
    else
        return query(x, Rson);
}

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        v.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &a[i].first, &a[i].second);
            v.push_back(a[i].first);
            v.push_back(a[i].second);
            v.push_back(a[i].second + 1);
        }
        sort(v.begin(), v.end());
        int N = unique(v.begin(), v.end()) - v.begin();
        for (int i = 0; i < n; i++)
        {
            a[i].first = lower_bound(v.begin(), v.begin() + N, a[i].first) - v.begin() + 1;
            a[i].second = lower_bound(v.begin(), v.begin() + N, a[i].second) - v.begin() + 1;
            //printf("%d %d\n", a[i].first, a[i].second);
        }
        build(1, N, 1);
        for (int i = 0; i < n; i++)
            update(a[i].first, a[i].second, i, 1, N, 1);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int col = query(i, 1, N, 1);
            if (col != -1 && vis[col] == 0)
            {
                vis[col] = 1;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}