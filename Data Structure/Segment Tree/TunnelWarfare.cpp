// Tunnel Warfare, HDU1540

#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
#define lm (m - (m >> 1))
#define rm (m >> 1)

const int maxn = 50005;
int ls[maxn << 2], rs[maxn << 2], ms[maxn << 2];

void pushup(int rt, int m)
{
    ls[rt] = ls[lson] + (ls[lson] == lm) * ls[rson];
    rs[rt] = rs[rson] + (rs[rson] == rm) * rs[lson];
    ms[rt] = max(max(ms[lson], ms[rson]), rs[lson] + ls[rson]);
}
void build(int l, int r, int rt)
{
    ls[rt] = rs[rt] = ms[rt] = r - l + 1;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}
void update(int x, int val, int l, int r, int rt)
{
    if (l == r)
    {
        ls[rt] = rs[rt] = ms[rt] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, val, Lson);
    if (m < x)
        update(x, val, Rson);
    pushup(rt, r - l + 1);
}
int query(int x, int l, int r, int rt)
{
    if (l == r || ms[rt] == r - l + 1)
        return ms[rt];
    int m = (l + r) >> 1;
    if (x <= m)
    {
        if (x >= m - rs[lson] + 1)
            return query(x, Lson) + query(m + 1, Rson);
        return query(x, Lson);
    }
    else
    {
        if (x < m + ls[rson] + 1)
            return query(x, Rson) + query(m, Lson);
        return query(x, Rson);
    }
}

int main()
{
    int n, m, t;
    char cmd[3];
    while (~scanf("%d%d", &n, &m))
    {
        stack<int> s;
        build(1, n, 1);
        while (m--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'R')
            {
                update(s.top(), 1, 1, n, 1);
                s.pop();
                continue;
            }
            scanf("%d", &t);
            if (cmd[0] == 'D')
            {
                s.push(t);
                update(t, 0, 1, n, 1);
            }
            else
                printf("%d\n", query(t, 1, n, 1));
        }
    }
    return 0;
}
