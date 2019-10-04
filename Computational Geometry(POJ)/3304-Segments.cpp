#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;
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
//l1是直线,l2是线段
bool segxline(line l1, line l2)
{
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}
double dist(point a, point b) { return sqrt((a - b) * (a - b)); }

const int maxn = 110;
line L[maxn];

bool check(line l1, int n)
{
    if (sgn(dist(l1.s, l1.e)) == 0)
        return false;
    for (int i = 0; i < n; ++i)
        if (segxline(l1, L[i]) == false)
            return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    double x1, y1, x2, y2;
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            L[i] = line(point(x1, y1), point(x2, y2));
        }
        bool flag = false;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (check(line(L[i].s, L[j].s), n) || check(line(L[i].s, L[j].e), n) || check(line(L[i].e, L[j].s), n) || check(line(L[i].e, L[j].e), n))
                {
                    flag = true;
                    break;
                }
        if (flag)
            printf("Yes!\n");
        else
            printf("No!\n");
    }
    return 0;
}