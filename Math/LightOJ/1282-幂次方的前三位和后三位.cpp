// n^k = a.bc * 10^m <=> lg(n^k) = lg(a.bc * 10^m)
// <=> k * lg(n) = lg(a.bc) + lg(10^m) = lg(a.bc) + m
// m为k * lg(n)的整数部分，lg(a.bc)为k * lg(n)的小数部分
// x = lg(a.bc) = k * lg(n) - m = k * lg(n) - (int)(k * lg(n))
// a.bc = pow(10, x) <=> abc = a.bc * 100
#include <cmath>
#include <cstdio>
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

int main()
{
    int T;
    scanf("%d", &T);
    ll n, k;
    for (int i = 1; i <= T; ++i)
    {
        scanf("%lld%lld", &n, &k);
        double x = k * log10(n) - (int)(k * log10(n));
        int res1 = pow(10, x) * 100;
        ll res2 = mod_pow(n, k, 1000);
        // 注意输出为3位，如果后三位是022，那么必须输出022，不能输出22
        printf("Case %d: %d %03lld\n", i, res1, res2);
    }
    return 0;
}