// HDU 3037
#include <cstdio>
using namespace std;

typedef long long ll;
const int maxp = 100005;
ll F[maxp];
void init(ll p)
{
    F[0] = 1;
    for (int i = 1; i <= p; ++i)
        F[i] = F[i - 1] * i % p;
}
ll inv(ll n, ll p) //阶乘n!的逆元
{
    if (n == 1)
        return 1;
    return inv(p % n, p) * (p - p / n) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    init(p);
    ll res = 1;
    while (n && m)
    {
        ll a = n % p, b = m % p;
        if (a < b)
            return 0;
        res = res * F[a] % p * inv(F[b] * F[a - b] % p, p) % p;
        n /= p, m /= p;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    int n, m, p;
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        printf("%lld\n", Lucas(n + m, m, p));
    }
    return 0;
}