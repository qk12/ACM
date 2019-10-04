#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-6;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    // 两点是否重合
    bool operator==(point &b) { return zero(x - b.x) && zero(y - b.y); }
    // 点积(以原点为基准)
    double operator*(const point &b) const { return x * b.x + y * b.y; }
    // 叉积(以原点为基准)
    double operator^(const point &b) const { return x * b.y - y * b.x; }
};
struct line
{
    point s, e;
    line() {}
    line(point ss, point ee) { s = ss, e = ee; }
};

int check(point &p0, point &p1, point &p2) //点P在直线AB右边 ⟺ PA × PB >= 0
{
    return (p1 - p0) ^ (p2 - p0);
}
bool cmp(const line &a, const line &b) { return a.s.x < b.s.x; }

const int maxn = 1005;
line L[maxn];
int ans[maxn], cnt[maxn];
int main()
{
    int n, m, x1, y1, x2, y2;
    while (scanf("%d", &n), n)
    {
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        int Ui, Li;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &Ui, &Li);
            L[i] = line(point(Ui, y1), point(Li, y2));
        }
        L[n] = line(point(x2, y1), point(x2, y2));
        sort(L, L + n + 1, cmp);
        int x, y;
        point p;
        memset(ans, 0, sizeof(ans)), memset(cnt, 0, sizeof(cnt));
        while (m--)
        {
            scanf("%d%d", &x, &y);
            p = point(x, y);
            int l = 0, r = n + 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (check(p, L[mid].s, L[mid].e) >= 0)
                    l = mid + 1;
                else
                    r = mid;
            }
            ans[l]++;
        }
        for (int i = 0; i <= n; i++)
            if (ans[i] > 0)
                ++cnt[ans[i]];
        printf("Box\n");
        for (int i = 1; i <= n; i++)
            if (cnt[i] > 0)
                printf("%d: %d\n", i, cnt[i]);
    }
    return 0;
}
