// POJ 1061
// x + k*m ≡ y + k*n (mod L)
// k * (m-n) ≡ y - x (mod L)
// k * (m-n) + t * L = y - x
#include <iostream>
using namespace std;

typedef long long ll;
ll extgcd(ll a, ll b, ll &x, ll &y) //返回值为gcd(a,b)
{
    ll res = a;
    if (b != 0)
        res = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else
        x = 1, y = 0;
    return res;
}
ll solve(ll a, ll b, ll c) //ax + by = c
{
    ll d, x, y;
    d = extgcd(a, b, x, y);
    if (c % d != 0) //c % gcd(a,b) != 0 无解
        return -1;
    ll x2 = x * c / d, m = b / d;
    return (x2 % m + m) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll c = y - x, a = m - n;
    if (a < 0)
    {
        a = -a;
        c = -c;
    };
    ll res = solve(a, L, c);
    if (res == -1)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
    return 0;
}
