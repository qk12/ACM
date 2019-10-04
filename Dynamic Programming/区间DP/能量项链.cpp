// Luogu 1063
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105 << 1;
int n, m;
int A[maxn], dp[maxn][maxn];

int dfs(int L, int R)
{
    if (L == R)
        return dp[L][R] = 0;
    if (dp[L][R])
        return dp[L][R];
    int res = 0;
    for (int k = L; k < R; ++k)
        res = max(res, dfs(L, k) + dfs(k + 1, R) + A[L] * A[k + 1] * A[R + 1]);
    return dp[L][R] = res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        A[i + n] = A[i]; //因为是环所以保存为长度为2n的链以保证不会漏解
    }

    dfs(1, 2 * n); //搜索出1-2n的最大得分与最小得分

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(dp[i][n + i - 1], ans);
    cout << ans << endl;
    return 0;
}