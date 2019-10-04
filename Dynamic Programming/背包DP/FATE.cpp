// HDU 2159
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int dp[maxn][maxn];

int main()
{
    int n, m, k, s;
    int a, b;
    while (cin >> n >> m >> k >> s)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            for (int j = 1; j <= s; j++)
                for (int k = b; k <= m; k++)
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - b] + a);
        }
        if (dp[s][m] < n)
            cout << "-1" << endl;
        else
        {
            int ans = m;
            for (int i = 1; i <= s; i++)
                for (int j = 1; j <= m; j++)
                {
                    if (dp[i][j] >= n)
                        ans = min(ans, j);
                }
            cout << m - ans << endl;
        }
    }
    return 0;
}