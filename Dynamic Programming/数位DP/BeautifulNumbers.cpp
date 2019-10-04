// CF 55D
#include <bits/stdc++.h>
using namespace std;

const int mod = 2520;
typedef long long ll;
int a[20];
ll dp[20][256 + 5][mod + 5];
//dp[i][j][k]表示当前是第i位，2~9的数的集合为j，模2520为k的方案数
int get(int i, int S) //2~9
{
    return i < 2 ? S : S | (1 << (i - 2));
}
ll dfs(int pos, int S, int sum, bool lead, bool limit)
{
    if (pos == -1)
    {
        for (int i = 2; i <= 9; i++)
            if (S & (1 << (i - 2)) && sum % i != 0)
                return 0;
        return 1;
    }
    if (!limit && !lead && dp[pos][S][sum] != -1)
        return dp[pos][S][sum];
    int up = limit ? a[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; ++i)
    {
        res += dfs(pos - 1, get(i, S), (sum * 10 + i) % mod, lead && i == 0, limit && i == up);
    }
    if (!limit && !lead)
        dp[pos][S][sum] = res;
    return res;
}
ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1, 0, 0, true, true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    ll x, y;
    while (T--)
    {
        cin >> x >> y;
        cout << solve(y) - solve(x - 1) << endl;
    }
    return 0;
}
