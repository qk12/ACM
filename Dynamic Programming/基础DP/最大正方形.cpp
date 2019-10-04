// Luogu 1387
#include <iostream>
using namespace std;

const int maxn = 105;
int a[maxn][maxn];
int dp[maxn][maxn];
int n, m;
int ans;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j]; //因为只需用到i，j上方，左方，左上方的信息，读入同步处理
            if (a[i][j] == 1)
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            ans = max(ans, dp[i][j]); //同步更新答案
        }
    cout << ans << endl;
    return 0;
}