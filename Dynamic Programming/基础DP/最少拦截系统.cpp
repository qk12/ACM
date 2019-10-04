// HDU 1257
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5005;
int a[maxn], dp[maxn];
int n;
int LIS() //返回最长不下降子序列的长度
{
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i)
        *lower_bound(dp, dp + n, a[i]) = a[i];
    return lower_bound(dp, dp + n, INF) - dp;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        printf("%d\n", LIS());
    }
    return 0;
}