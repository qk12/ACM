#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    long long n;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%lld", &n);
        long long sum = 0;
        int m = sqrt(n);
        for (int i = 1; i <= m; ++i)
            sum += (n / i - n / (i + 1)) * i + n / i;
        if (m == n / m)
            sum -= m;
        printf("Case %d: %lld\n", k, sum);
    }
    return 0;
}