// HDU 1711
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxm = 1e4 + 5;
int a[maxn], b[maxm];
int kmp[maxm];
void initkmp(int x[], int m)
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
            pos = kmp[pos];
        kmp[++i] = ++pos;
    }
}
int KMP(int x[], int m, int y[], int n)
{
    initkmp(x, m);
    int i = 0, pos = 0, cnt = 0;
    while (i < n)
    {
        while (pos != -1 && y[i] != x[pos])
            pos = kmp[pos];
        ++i, ++pos;
        if (pos >= m)
        {
            ++cnt, pos = kmp[pos];
            break;
        }
    }
    if (cnt == 0)
        return -1;
    else
        return i + 1 - m;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < m; ++i)
            scanf("%d", b + i);
        printf("%d\n", KMP(b, m, a, n));
    }
    return 0;
}