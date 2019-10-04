// HDU 1576
#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 9973;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1, y = 0;
    }
    return d;
}

int mod_inverse(int a, int mod)
{
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
}

int main()
{
    int T;
    cin >> T;
    int n, b;
    while (T--)
    {
        cin >> n >> b;
        cout << n * mod_inverse(b, mod) % mod << endl;
    }
    return 0;
}