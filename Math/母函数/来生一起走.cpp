// HDU 2189
#include <bits/stdc++.h>
using namespace std;

const int maxn = 155;
int prime[maxn];
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
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
const int maxm = 1000; //最大有多少项相乘
int a[maxm], b[maxm];  //a[M]中存最终项系数;b[M]中存取中间变量;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getPrime(maxn);
    int T;
    cin >> T;
    int n; //n为所求的指数的值
    while (T--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 0; i <= n; i += 2) //初始化第一个式子:(1+X^2+X^4+...)
        {
            a[i] = 1;
        }
        for (int i = 2; i <= prime[0]; ++i)
        {
            for (int j = 0; j <= n; ++j)
                for (int k = 0; k + j <= n; k += prime[i])
                    b[j + k] += a[j];
            for (int j = 0; j <= n; ++j)
            {
                a[j] = b[j];
                b[j] = 0;
            }
        }
        cout << a[n] << endl;
    }
    return 0;
}