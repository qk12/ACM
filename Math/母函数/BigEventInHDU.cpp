// HDU 1171
#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
const int maxm = 125005;
int n, m;
int W[maxn], V[maxn], dp[maxm];
int a[maxn];
void ZeroOnePack(int w, int v)
{
    for (int j = m; j >= w; --j)
        dp[j] = max(dp[j], dp[j - w] + v);
}
void CompletePack(int w, int v)
{
    for (int j = w; j <= m; ++j)
        dp[j] = max(dp[j], dp[j - w] + v);
}
void MultiplePack(int w, int v, int num)
{
    if (w * num >= m)
        CompletePack(w, v);
    else
    {
        int k = 1;
        while (k < num)
        {
            ZeroOnePack(k * w, k * v);
            num -= k;
            k <<= 1;
        }
        ZeroOnePack(num * w, num * v);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (n < 0)
            break;
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &W[i], &a[i]);
            V[i] = W[i];
            sum += W[i] * a[i];
        }
        m = sum / 2;
        for (int i = 0; i < n; ++i)
            MultiplePack(W[i], V[i], a[i]);
        printf("%d %d\n", sum - dp[m], dp[m]);
    }
    return 0;
}