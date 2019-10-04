// HDU 4734
#include <bits/stdc++.h>
using namespace std;

int a[10];
int dp[10][4700];
int A, B;
int dfs(int pos, int state, bool lead, bool limit)
{
    if (pos == -1)
        return state >= 0;
    if (!limit && !lead && dp[pos][state] != -1)
        return dp[pos][state];
    int up = limit ? a[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; ++i)
    {
        if (state - i * (1 << pos) >= 0)
            ans += dfs(pos - 1, state - i * (1 << pos), lead && i == 0, limit && i == up);
    }
    if (!limit && !lead)
        dp[pos][state] = ans;
    return ans;
}
int F(int x)
{
    int res = 0, len = 0;
    while (x)
    {
        res += (x % 10) * (1 << len);
        ++len;
        x /= 10;
    }
    return res;
}
int solve(int x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1, F(A), true, true);
}

int main()
{
    int T;
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d\n", k, solve(B));
    }
    return 0;
}
