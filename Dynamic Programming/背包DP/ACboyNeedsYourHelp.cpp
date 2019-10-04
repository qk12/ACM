// HDU 1712
#include <bits/stdc++.h>
using namespace std;

int dp[105], value[105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 || m == 0)
            break;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> value[i][j];
        for (int i = n; i >= 1; --i)
            for (int j = m; j >= 0; --j)
                for (int k = 0; k <= j; ++k)
                    dp[j] = max(dp[j], dp[j - k] + value[i][k]);
        cout << dp[m] << endl;
    }
    return 0;
}
