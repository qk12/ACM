// POJ 2187
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
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

bool cmp(const point &a, const point &b) //字典序比较
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
vector<point> get(point p[], int n)
{
    sort(p, p + n, cmp);
    int k = 0;                //凸包的顶点数
    vector<point> res(n * 2); //构造中的凸包
    //构造凸包的下侧
    for (int i = 0; i < n; ++i)
    {
        while (k > 1 && ((res[k - 1] - res[k - 2]) ^ (p[i] - res[k - 1])) <= 0)
            --k;
        res[k++] = p[i];
    }
    //构造凸包的上侧
    for (int i = n - 2, t = k; i >= 0; --i)
    {
        while (k > t && ((res[k - 1] - res[k - 2]) ^ (p[i] - res[k - 1])) <= 0)
            --k;
        res[k++] = p[i];
    }
    res.resize(k - 1);
    return res;
}

double dist(point a, point b) { return (a - b) * (a - b); }

int n;
point p[50005];

void solve()
{
    vector<point> res = get(p, n);
    double ans = 0;
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < i; ++j)
            ans = max(ans, dist(res[i], res[j]));
    printf("%.0f\n", ans);
}

int main()
{
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        p[i] = point(x, y);
    }
    solve();
    return 0;
}