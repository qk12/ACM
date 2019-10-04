#include <cstdio>
using namespace std;

const int maxn = 1e8 + 5;
double num[1000005];
void init() //把n分成大小为100的1e6份，每一份存下来
{
    double sum = 0;
    for (int i = 1; i < maxn; ++i)
    {
        sum += 1.0 / i;
        if (i % 100 == 0)
            num[i / 100] = sum;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    long long n;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%lld", &n);
        long long x = n / 100;
        double sum = num[x];
        for (int i = 100 * x + 1; i <= n; ++i)
        {
            sum += 1.0 / i;
        }
        printf("Case %d: %.10f\n", k, sum);
    }
    return 0;
}