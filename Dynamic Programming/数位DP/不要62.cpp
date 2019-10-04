// HDU 2089
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[20];
ll dp[20][20];
ll dfs(int pos, int state, bool lead, bool limit)
{
    if (pos == -1)
        return 1;
    if (!limit && !lead && dp[pos][state] != -1)
        return dp[pos][state];
    int up = limit ? a[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; ++i)
    {
        if (i != 4 && !(state == 6 && i == 2))
            res += dfs(pos - 1, i, lead && i == 0, limit && i == up);
    }
    if (!limit && !lead)
        dp[pos][state] = res;
    return res;
}
ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1, 0, true, true);
}

int main()
{
    ll x, y;
    memset(dp, -1, sizeof(dp));
    while (scanf("%lld%lld", &x, &y))
    {
        if (x == 0 && y == 0)
            break;
        printf("%lld\n", solve(y) - solve(x - 1));
    }
    return 0;
}
