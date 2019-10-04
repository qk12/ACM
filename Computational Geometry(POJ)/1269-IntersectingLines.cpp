#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
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

pair<int, point> spoint(line l1, line l2)
{
    point res = l1.s;
    if (sgn((l1.s - l1.e) ^ (l2.s - l2.e)) == 0)
        return {sgn((l1.s - l2.e) ^ (l2.s - l2.e)) != 0, res};
    double t = ((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
    res.x += (l1.e.x - l1.s.x) * t;
    res.y += (l1.e.y - l1.s.y) * t;
    return {2, res};
}

int main()
{
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    printf("INTERSECTING LINES OUTPUT\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        line l1(point(x1, y1), point(x2, y2));
        line l2(point(x3, y3), point(x4, y4));
        pair<int, point> ans = spoint(l1, l2);
        if (ans.first == 1)
            printf("NONE\n");
        else if (ans.first == 0)
            printf("LINE\n");
        else if (ans.first == 2)
            printf("POINT %.2f %.2f\n", ans.second.x, ans.second.y);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
