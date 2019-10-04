#include <cstdio>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
int prime[maxn]; //prime[0]储存素数的个数，素数下标从1开始
bool is_prime[maxn];
void getPrime(int n)
{
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxn; i++)
    {
        if (is_prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= n / i; j++)
        {
            is_prime[i * prime[j]] = false; //找到的素数的倍数不访问
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    getPrime(maxn);
    int T;
    scanf("%d", &T);
    ll a, b;
    for (int i = 1; i <= T; ++i)
    {
        scanf("%lld%lld", &a, &b);
        if (b * b >= a)
        {
            printf("Case %d: 0\n", i);
            continue;
        }
        ll ans = 1, cnt;
        ll temp = a;
        for (int i = 1; prime[i] * prime[i] <= a && i <= prime[0]; ++i)
        {
            cnt = 0;
            if (a % prime[i] == 0)
            {
                while (a % prime[i] == 0)
                {
                    ++cnt;
                    a /= prime[i];
                }
            }
            ans *= (cnt + 1);
        }
        if (a > 1)
            ans *= 2;
        ans /= 2;
        for (int i = 1; i < b; ++i)
            if (temp % i == 0)
                --ans;
        printf("Case %d: %lld\n", i, ans);
    }
    return 0;
}