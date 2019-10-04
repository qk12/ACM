// POJ 3252
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
int a[70];
ll dp[70][70][70];
ll dfs(int pos, int zero, int one, bool lead, bool limit)
{
    if (pos == -1)
        return zero >= one;
    if (!limit && !lead && dp[pos][zero][one] != -1)
        return dp[pos][zero][one];
    int up = limit ? a[pos] : 1;
    ll res = 0;
    for (int i = 0; i <= up; ++i)
    {
        if (i == 0 && lead) //前导0
            res += dfs(pos - 1, 0, 0, lead && i == 0, limit && i == up);
        else
        {
            if (i == 0) //不能用++zero/++one
                res += dfs(pos - 1, zero + 1, one, lead && i == 0, limit && i == up);
            else if (i == 1)
                res += dfs(pos - 1, zero, one + 1, lead && i == 0, limit && i == up);
        }
    }
    if (!limit && !lead)
        dp[pos][zero][one] = res;
    return res;
}
ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 2;
    while (x /= 2);
    return dfs(pos - 1, 0, 0, true, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ll x, y;
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", solve(y) - solve(x - 1));
    return 0;
}
