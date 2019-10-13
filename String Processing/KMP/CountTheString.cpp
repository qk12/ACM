// HDU 3336
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 10007;
char x[maxn];
int kmp[maxn];
void initkmp(char x[], int m)
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
            pos = kmp[pos];
        kmp[++i] = ++pos;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", x);
        initkmp(x, n);
        int sum = n;
        for (int i = 1; i <= n; ++i)
        {
            if (kmp[i] > 0) //非零说明某个前缀成功匹配了一次.
                sum = (sum + 1) % mod;
        }
        printf("%d\n", sum);
    }
    return 0;
}