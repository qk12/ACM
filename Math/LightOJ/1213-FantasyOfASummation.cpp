#include <iostream>
using namespace std;

typedef long long ll;
ll mod_pow(ll x, ll n, ll mod) //x的n次幂对mod取模
{
    ll res = 1;
    if (n == 0)
        return res %= mod; //注意：1%1不等于1而等于0
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod, n >>= 1;
    }
    return res;
}

ll a[1005];
int main()
{
    int T;
    cin >> T;
    ll n, k, mod;
    for (int p = 1; p <= T; ++p)
    {
        cin >> n >> k >> mod;
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum = (sum + a[i]) % mod; //取模，不然会溢出
        }
        sum = (sum * k) % mod * mod_pow(n, k - 1, mod) % mod;
        cout << "Case " << p << ": " << sum << endl;
    }
    return 0;
}