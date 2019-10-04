// HDU 1243
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
int dp[maxn][maxn];
char z[maxn];
char x[maxn], y[maxn];
int s[30];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%s", z);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &s[z[i] - 'a']);
        }
        scanf("%s%s", x, y);
        memset(dp, 0, sizeof(dp));
        int n = strlen(x), m = strlen(y);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (x[i] == y[j])
                    dp[i + 1][j + 1] = dp[i][j] + s[x[i] - 'a'];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}