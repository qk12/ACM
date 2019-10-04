// POJ 2115
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
    ll a, b, c, k;
    while (cin >> a >> b >> c >> k)
    {
        if (a + b + c + k == 0)
            break;
        ll mod = 1LL << k; //对于long long型变量，需要这样写位运算
        ll res = solve(c, mod, b - a);
        if (res == -1)
            cout << "FOREVER" << endl;
        else
            cout << res << endl;
    }
    return 0;
}