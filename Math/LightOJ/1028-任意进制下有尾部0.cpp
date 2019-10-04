#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
int prime[80005]; //prime[0]储存素数的个数，素数下标从1开始
bool is_prime[maxn];
void getPrime(int n)
{
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
        {
            is_prime[i * prime[j]] = false; //找到的素数的倍数不访问
            if (i % prime[j] == 0)
                break;
        }
    }
}
map<int, int> res;
void primer_factor(ll n) //素因数分解
{
    res.clear();
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= n; ++i)
        while (n % prime[i] == 0)
            ++res[prime[i]], n /= prime[i];
    if (n != 1)
        res[n] = 1;
}

int main()
{
    getPrime(1e6);
    int T;
    scanf("%d", &T);
    ll n;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%lld", &n);
        primer_factor(n);
        ll ans = 1;
        for (auto &i : res)
            ans *= (1 + i.second);
        printf("Case %d: %lld\n", k, ans - 1);
    }
    return 0;
}