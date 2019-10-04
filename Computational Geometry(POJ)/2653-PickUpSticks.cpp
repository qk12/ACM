#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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

bool segxseg(line &l1, line &l2)
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
           max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
           max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
           max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
           sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
           sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}
line L[100005];
bool vis[100005];
int main()
{
    int n;
    double x1, y1, x2, y2;
    while (scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            L[i] = line(point(x1, y1), point(x2, y2));
            vis[i] = true;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
                if (segxseg(L[i], L[j]))
                {
                    vis[i] = false;
                    break;
                }
        }
        printf("Top sticks: ");
        bool flag = true;
        for (int i = 1; i <= n; ++i)
            if (vis[i])
            {
                if (flag)
                    flag = false;
                else
                    printf(", ");
                printf("%d", i);
            }
        printf(".\n");
    }
    return 0;
}
