// HDU 6025
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int a[maxn];
int x[maxn], y[maxn];

inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        x[1] = a[1];
        for (int i = 2; i <= n; ++i)
        {
            x[i] = gcd(x[i - 1], a[i]);
        }
        y[n] = a[n];
        for (int i = n - 1; i >= 1; --i)
        {
            y[i] = gcd(y[i + 1], a[i]);
        }
        int ans = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            ans = max(ans, gcd(x[i - 1], y[i + 1]));
        }
        ans = max(ans, max(x[n - 1], y[2]));
        cout << ans << endl;
    }
    return 0;
}