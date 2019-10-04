// HDU 1059
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 15;
const int maxm = 120005;
int n, m;                       //物品种数、容量
int w[maxn], v[maxn], dp[maxm]; //weight、value

void ZeroOnePack(int weight, int value)
{
    for (int j = m; j >= weight; --j)
        dp[j] = max(dp[j], dp[j - weight] + value);
}
void CompletePack(int weight, int value)
{
    for (int j = weight; j <= m; ++j)
        dp[j] = max(dp[j], dp[j - weight] + value);
}
void MultiplePack(int weight, int value, int amount)
{
    if (weight * amount >= m)
        CompletePack(weight, value);
    else
    {
        int k = 1;
        while (k < amount)
        {
            ZeroOnePack(k * weight, k * value);
            amount -= k;
            k <<= 1;
        }
        ZeroOnePack(amount * weight, amount * value);
    }
}

int a[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6])
    {
        if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] == 0)
            break;
        cout << "Collection #" << ++kase << ":" << endl;
        dp[0] = 0;
        for (int i = 1; i < maxm; ++i)
            dp[i] = -INF;
        int sum = a[1] * 1 + a[2] * 2 + a[3] * 3 + a[4] * 4 + a[5] * 5 + a[6] * 6;
        if (sum % 2 != 0)
        {
            cout << "Can't be divided." << endl;
            cout << endl;
            continue;
        }
        m = sum / 2;
        for (int i = 1; i <= 6; ++i)
            MultiplePack(i, i, a[i]);
        if (dp[m] == m)
            cout << "Can be divided." << endl;
        else
            cout << "Can't be divided." << endl;
        cout << endl;
    }
    return 0;
}