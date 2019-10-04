// POJ 1700
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1005;
int a[maxn], dp[maxn];

int main()
{
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        dp[1] = a[1], dp[2] = a[2];
        for (int i = 3; i <= n; i++)
            dp[i] = min(dp[i - 1] + a[1] + a[i], dp[i - 2] + a[1] + a[i] + a[2] + a[2]);
        cout << dp[n] << endl;
    }
    return 0;
}