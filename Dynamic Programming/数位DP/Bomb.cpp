// HDU 3555
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[20];
ll dp[20][10][2];
ll dfs(int pos, int state, bool lead, bool limit, bool flag)
{
    if (pos == -1)
        return flag;
    if (!limit && !lead && dp[pos][state][flag] != -1)
        return dp[pos][state][flag];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; ++i)
        ans += dfs(pos - 1, i, lead && i == 0, limit && i == up, flag || (state == 4 && i == 9));
    if (!limit && !lead)
        dp[pos][state][flag] = ans;
    return ans;
}
ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1, 0, true, true, false);
}

int main()
{
    int T;
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    ll x;
    while (T--)
    {
        scanf("%lld", &x);
        printf("%lld\n", solve(x));
    }
    return 0;
}
