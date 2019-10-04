// UVA 10200
#include <cstdio>
using namespace std;

const double eps = 1e-6;
const int maxn = 10005;
int sum[maxn];
bool isPrime(int n) //简单写法
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
void init() //打表
{
    sum[0] = 1;
    for (int i = 1; i <= 10000; ++i)
    {
        sum[i] = sum[i - 1];
        if (isPrime(i * i + i + 41))
            ++sum[i];
    }
}

int main()
{
    init();
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int cnt;
        if (a == 0)
            cnt = sum[b];
        else
            cnt = sum[b] - sum[a - 1];
        double ans = 1.0 * cnt / (b - a + 1);
        printf("%.2lf\n", ans * 100 + eps); //调整精度
    }
    return 0;
}