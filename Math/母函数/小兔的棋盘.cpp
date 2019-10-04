// hDU 2067
#include <bits/stdc++.h>
using namespace std;

long long dp[40];
void init(int n)
{
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - j - 1];
    }
}
int main()
{
    int kase = 0;
    int n;
    init(35);
    while (cin >> n, n != -1)
    {
        cout << ++kase << " " << n << " " << dp[n] * 2 << endl;
    }
}
