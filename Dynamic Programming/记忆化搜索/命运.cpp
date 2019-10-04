// HDU 2571
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
const int INF = 0x3f3f3f3f;
int a[maxn][1005];
int dp[maxn][1005];
int n, m;

int dfs(int i, int j)
{
    if (i > n || j > m)
        return -INF;
    if (dp[i][j] != -INF)
        return dp[i][j];
    int res = -INF;
    res = max(dfs(i + 1, j), dfs(i, j + 1));
    for (int k = 2; k * j <= m; ++k)
        res = max(res, dfs(i, k * j));
    return dp[i][j] = res + a[i][j];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                dp[i][j] = -INF;
            }
        dp[n][m] = a[n][m];
        cout << dfs(1, 1) << endl;
    }
    return 0;
}
