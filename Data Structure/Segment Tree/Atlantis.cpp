// HDU 1542
#include <bits/stdc++.h>
#define lson pos << 1     //左儿子
#define rson pos << 1 | 1 //右儿子
#define Lson L, mid, lson
#define Rson mid + 1, R, rson
using namespace std;

const int maxn = 105;
map<double, int> Hash;
map<int, double> rHash;

struct line
{
    double l, r, h;
    int val;
    line(double l = 0, double r = 0, double h = 0, int val = 0) : l(l), r(r), h(h), val(val) {}
    bool operator<(const line &A) const { return h < A.h; }
};

struct Node
{
    int cover;
    double len;
} seg[maxn << 2];

void build(int L, int R, int pos)
{
    seg[pos].cover = seg[pos].len = 0;
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    build(Lson);
    build(Rson);
}

void pushup(int L, int R, int pos)
{
    if (seg[pos].cover > 0)
        seg[pos].len = rHash[R + 1] - rHash[L]; // [l,r)
    else if (L == R)
        seg[pos].len = 0;
    else
        seg[pos].len = seg[lson].len + seg[rson].len;
}

void update(int x, int y, int val, int L, int R, int pos)
{
    if (x <= L && y >= R)
    {
        seg[pos].cover += val;
        pushup(L, R, pos);
        return;
    }
    int mid = (L + R) >> 1;
    if (x <= mid)
        update(x, y, val, Lson);
    if (y >= mid + 1)
        update(x, y, val, Rson);
    pushup(L, R, pos);
}

int main()
{
    int n, kase = 0;
    while (scanf("%d", &n), n)
    {
        double x1, x2, y1, y2;
        vector<line> a;
        set<double> xval;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a.emplace_back(x1, x2, y1, 1);
            a.emplace_back(x1, x2, y2, -1);
            xval.insert(x1);
            xval.insert(x2);
        }
        // 离散化
        Hash.clear(), rHash.clear();
        int cnt = 0;
        for (auto &v : xval)
        {
            Hash[v] = ++cnt;
            rHash[cnt] = v;
        }
        sort(a.begin(), a.end());
        build(1, cnt, 1);
        double ans = 0;
        for (int i = 0; i < a.size() - 1; i++)
        {
            update(Hash[a[i].l], Hash[a[i].r] - 1, a[i].val, 1, cnt, 1); //[l,r)
            ans += (a[i + 1].h - a[i].h) * seg[1].len;
        }
        printf("Test case #%d\n", ++kase);
        printf("Total explored area: %.2lf\n\n", ans);
    }
}