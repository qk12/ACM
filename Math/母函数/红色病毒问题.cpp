// HDU 2065
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    if (n == 0)
        return res %= mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod, n >>= 1;
    }
    return res;
}

int main()
{
    int T;
    while (cin >> T, T)
    {
        ll n;
        int kase = 0;
        while (T--)
        {
            cin >> n;
            ll ans = (mod_pow(2, n - 1, 100) + mod_pow(4, n - 1, 100)) % 100;
            cout << "Case " << ++kase << ": " << ans << endl;
        }
        cout << endl;
    }
    return 0;
}