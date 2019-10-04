#include <algorithm>
#include <cmath>
#include <cstdio>
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
double dist(point a, point b) { return sqrt((a - b) * (a - b)); }
bool segxseg(line l1, line l2) //判断线段相交
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
           max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
           max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
           max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
           sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
           sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

const int maxn = 100;
line L[maxn];
double dis[maxn][maxn];
const double INF = 1e20;
int main()
{
    int n;
    double x, y1, y2, y3, y4;
    while (scanf("%d", &n))
    {
        if (n == -1)
            break;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
            L[2 * i - 1] = line(point(x, y1), point(x, y2));
            L[2 * i] = line(point(x, y3), point(x, y4));
        }
        for (int i = 0; i <= 4 * n + 1; i++)
            for (int j = 0; j <= 4 * n + 1; j++)
            {
                if (i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = INF;
            }
        for (int i = 1; i <= 4 * n; i++)
        {
            int lid = (i + 3) / 4;
            bool flag = true;
            point tmp;
            if (i & 1)
                tmp = L[(i + 1) / 2].s;
            else
                tmp = L[(i + 1) / 2].e;
            for (int j = 1; j < lid; j++)
                if (segxseg(L[2 * j - 1], line(point(0, 5), tmp)) == false && segxseg(L[2 * j], line(point(0, 5), tmp)) == false)
                    flag = false;
            if (flag)
                dis[0][i] = dis[i][0] = dist(point(0, 5), tmp);
            flag = true;
            for (int j = lid + 1; j <= n; j++)
                if (segxseg(L[2 * j - 1], line(point(10, 5), tmp)) == false && segxseg(L[2 * j], line(point(10, 5), tmp)) == false)
                    flag = false;
            if (flag)
                dis[i][4 * n + 1] = dis[4 * n + 1][i] = dist(point(10, 5), tmp);
        }
        for (int i = 1; i <= 4 * n; i++)
            for (int j = i + 1; j <= 4 * n; j++)
            {
                int lid1 = (i + 3) / 4;
                int lid2 = (j + 3) / 4;
                bool flag = true;
                point p1, p2;
                if (i & 1)
                    p1 = L[(i + 1) / 2].s;
                else
                    p1 = L[(i + 1) / 2].e;
                if (j & 1)
                    p2 = L[(j + 1) / 2].s;
                else
                    p2 = L[(j + 1) / 2].e;
                for (int k = lid1 + 1; k < lid2; k++)
                    if (segxseg(L[2 * k - 1], line(p1, p2)) == false && segxseg(L[2 * k], line(p1, p2)) == false)
                        flag = false;
                if (flag)
                    dis[i][j] = dis[j][i] = dist(p1, p2);
            }
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (segxseg(L[2 * i - 1], line(point(0, 5), point(10, 5))) == false && segxseg(L[2 * i], line(point(0, 5), point(10, 5))) == false)
                flag = false;
        if (flag)
            dis[0][4 * n + 1] = dis[4 * n + 1][0] = 10;
        for (int k = 0; k <= 4 * n + 1; k++)
            for (int i = 0; i <= 4 * n + 1; i++)
                for (int j = 0; j <= 4 * n + 1; j++)
                    if (dis[i][k] + dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
        printf("%.2f\n", dis[0][4 * n + 1]);
    }
    return 0;
}