// Luogu 2602
#include <iostream>
using namespace std;

typedef long long ll;
int a[20];
ll dp[20][20];
ll dfs(int pos, int state, bool lead, bool limit, int dig)
{
    if (pos == -1)
        return state;
    if (!limit && !lead && dp[pos][state] != -1)
        return dp[pos][state];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (pos != 0 && lead && i == 0)
            ans += dfs(pos - 1, 0, lead && i == 0, limit && i == up, dig);
        else
            ans += dfs(pos - 1, state + (i == dig), lead && i == 0, limit && i == up, dig);
    }
    if (!limit && !lead)
        dp[pos][state] = ans;
    return ans;
}

ll solve(ll x, int dig)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    memset(dp, -1, sizeof(dp));
    return dfs(pos - 1, 0, true, true, dig);
}

int main()
{
    ll x, y;
    cin >> x >> y;
    for (int i = 0; i <= 9; ++i)
    {
        if (i != 9)
            cout << solve(y, i) - solve(x - 1, i) << ' ';
        else
            cout << solve(y, i) - solve(x - 1, i) << endl;
    }
    return 0;
}