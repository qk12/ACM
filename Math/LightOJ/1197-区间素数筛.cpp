#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 20;
bool is_prime[maxn]; //is_prime[i-a]=true <=> i是素数
bool is_prime_small[maxn];
int segment_sieve(ll a, ll b) //对区间[a,b)内的整数执行筛法
{
    for (int i = 0; (ll)i * i < b; ++i)
        is_prime_small[i] = true;
    for (int i = 0; i < b - a; ++i)
        is_prime[i] = true;
    for (int i = 2; (ll)i * i < b; ++i)
        if (is_prime_small[i])
        {
            for (int j = 2 * i; (ll)j * j < b; j += i) //筛[2,sqrt(b))
                is_prime_small[i] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) //筛[a,b)
                is_prime[j - a] = false;
        }
    int cnt = 0;
    for (ll i = 0; i < b - a; ++i)
        if (is_prime[i])
            ++cnt;
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);
    ll a, b;
    for (int i = 1; i <= T; ++i)
    {
        scanf("%lld%lld", &a, &b);
        printf("Case %d: %d\n", i, segment_sieve(a, b + 1) - (a == 1));
    }
    return 0;
}
