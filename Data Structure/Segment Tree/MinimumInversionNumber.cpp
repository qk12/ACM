// HDU 1394
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int bit[5005], a[5005];
int n;

inline int lowbit(int x) { return x & -x; }
void add(int pos, int x)
{
    while (pos <= n)
        bit[pos] += x, pos += lowbit(pos);
}
ll sum(int pos)
{
    ll res = 0;
    while (pos > 0)
        res += bit[pos], pos -= lowbit(pos);
    return res;
}
ll solve()
{
    ll res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += i - 1 - sum(a[i]);
        add(a[i], 1);
    }
    return res;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ++a[i];
        }
        ll temp = solve();
        ll ans = temp;
        for (int i = 1; i <= n; ++i)
        {
            temp -= a[i] - 1;
            temp += n - a[i];
            ans = min(ans, temp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
