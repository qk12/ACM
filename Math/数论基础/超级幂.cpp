// UVA 11752
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 105;
int prime[maxn]; //prime[0]储存素数的个数，素数下标从1开始
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
ull mod_pow(ull x, ull n)
{
    ull res = 1;
    if (n == 0)
        return res;
    while (n > 0)
    {
        if (n & 1)
            res = res * x;
        x = x * x, n >>= 1;
    }
    return res;
}

int main()
{
    getPrime(100);
    set<ull> ans;
    ans.insert(1);
    int Max = (1 << 16);
    for (int i = 2; i < Max; ++i)
    {
        int top = ceil(64 * log10(2) / log10(i)) - 1; //ceil返回大于或者等于指定表达式的最小整数
        for (int j = 4; j <= top; ++j)
        {
            if (is_prime[j])
                continue;
            ans.insert(mod_pow(i, j));
        }
    }
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}