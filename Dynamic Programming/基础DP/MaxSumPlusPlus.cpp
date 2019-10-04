// HDU 1024
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int a[maxn], dp[maxn];
int premax[maxn]; //i-1时前j个数的最大dp

int solve(int n, int k)
{
    memset(dp, 0, sizeof(dp)), memset(premax, 0, sizeof(premax));
    int res;
    for (int i = 1; i <= k; ++i)
    {
        res = -INF;
        for (int j = i; j <= n; ++j)
        {
            dp[j] = max(dp[j - 1] + a[j], premax[j - 1] + a[j]);
            premax[j - 1] = res;
            res = max(res, dp[j]);
        }
    }
    return res;
}

int main()
{
    int n, k;
    while (scanf("%d%d", &k, &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        printf("%d\n", solve(n, k));
    }
    return 0;
}