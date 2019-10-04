#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 5;
int prime[665000]; //prime[0]储存素数的个数，素数下标从1开始
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
map<int, int> primer_factor(ll n)
{
    map<int, int> res;
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= n; ++i)
        while (n % prime[i] == 0)
            ++res[prime[i]], n /= prime[i];
    if (n != 1)
        res[n] = 1;
    return res;
}

int main()
{
    getPrime(maxn);
    int T;
    scanf("%d", &T);
    ll n;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%lld", &n);
        map<int, int> res = primer_factor(n);
        ll ans = 1;
        for (auto &i : res)
            ans *= (2 * i.second + 1);
        ans = (ans + 1) / 2;
        printf("Case %d: %lld\n", k, ans);
    }
    return 0;
}