#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn], dp[maxn];
int solve(int n)
{
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && dp[j] + a[i] > dp[i])
                dp[i] = dp[j] + a[i];
        res = max(res, dp[i]);
    }
    return res;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        cout << solve(n) << endl;
    }
    return 0;
}