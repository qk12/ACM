// HDU 2079
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
const int maxm = 45;
int n, m;
int w[maxn], dp[maxm];
int a[maxn];
void ZeroOnePack(int weight, int amount)
{
    for (int j = m; j >= weight; --j)
        for (int k = 1; k <= amount; ++k)
            if (weight * k <= j)
                dp[j] += dp[j - k * weight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> m >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> w[i] >> a[i];
        }
        for (int i = 0; i < n; ++i)
            ZeroOnePack(w[i], a[i]);
        cout << dp[m] << endl;
    }
    return 0;
}