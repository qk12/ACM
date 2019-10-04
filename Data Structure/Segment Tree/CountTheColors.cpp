#include <cstdio>
#include <cstring>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
const int maxn = 8005;
const int N = 8000;
int val[maxn << 2];
int cnt[maxn];

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
    if (x <= l && r <= y)
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
    int n;
    int a, b, c;
    while (~scanf("%d", &n))
    {
        clr(cnt, 0);
        build(0, N, 1);
        while (n--)
        {
            scanf("%d%d%d", &a, &b, &c);
            update(a, --b, c, 0, N, 1);
        }
        int last = -1;
        for (int i = 0; i <= N; i++)
        {
            int col = query(i, 0, N, 1);
            if (col != -1 && col != last)
                ++cnt[col];
            last = col;
        }
        for (int i = 0; i <= N; i++)
        {
            if (cnt[i])
                printf("%d %d\n", i, cnt[i]);
        }
        printf("\n");
    }
    return 0;
}