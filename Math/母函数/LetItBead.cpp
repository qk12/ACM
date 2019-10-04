// POJ 2409
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x;
        x = x * x, n >>= 1;
    }
    return res;
}

ll solve(int c, int n)
{
    if (n == 0)
        return 0;
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += mod_pow(c, gcd(i, n));
    if (n & 1)
        res += n * mod_pow(c, (n + 1) >> 1);
    else
        res += n / 2 * (1 + c) * mod_pow(c, n >> 1);
    return res / n / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c, n;
    while (cin >> c >> n)
    {
        if (c == 0 || n == 0)
            break;
        cout << solve(c, n) << endl;
    }
    return 0;
}