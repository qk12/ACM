// Luogu 1280
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int n, k, sum[10005], num = 1;
P a[10005];
int dp[10005];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i].first >> a[i].second;
        ++sum[a[i].first];
    }
    sort(a + 1, a + 1 + k, greater<P>());
    for (int i = n; i >= 1; --i) //倒着搜
    {
        if (sum[i] == 0)
            dp[i] = dp[i + 1] + 1;
        else
            for (int j = 1; j <= sum[i]; ++j)
            {
                dp[i] = max(dp[i], dp[i + a[num].second]);
                ++num; //当前已扫过的任务数
            }
    }
    cout << dp[1] << endl;
    return 0;
}