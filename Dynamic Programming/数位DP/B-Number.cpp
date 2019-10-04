// HDU 3652
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[20];
ll dp[20][10][15][2];
ll dfs(int pos, int state, bool lead, bool limit, bool flag, int sum)
{
    if (pos == -1)
        return flag && sum == 0;
    if (!limit && !lead && dp[pos][state][sum][flag] != -1)
        return dp[pos][state][sum][flag];
    int up = limit ? a[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; i++)
    {
        res += dfs(pos - 1, i, lead && i == 0, limit && i == up, flag || (state == 1 && i == 3), (sum * 10 + i) % 13);
    }
    if (!limit && !lead)
        dp[pos][state][sum][flag] = res;
    return res;
}
ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1, 0, true, true, false, 0);
}

int main()
{
    ll x;
    memset(dp, -1, sizeof(dp));
    while (scanf("%lld", &x) != EOF)
    {
        printf("%lld\n", solve(x));
    }
    return 0;
}
