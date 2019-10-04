// HDU 1028
#include <iostream>
using namespace std;

const int maxn = 125;
int dp[maxn][maxn];

int main()
{
    int n, m;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        m = n;
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= n; j++)
                if (j - i >= 0)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - i]);
                else
                    dp[i][j] = dp[i - 1][j];
        cout << dp[m][n] << endl;
    }
    return 0;
}