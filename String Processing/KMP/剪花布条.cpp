// HDU 2087
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int kmp[maxn];
char x[maxn], y[maxn];
void initkmp(int m)
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
            pos = kmp[pos];
        kmp[++i] = ++pos;
    }
}
int KMP(int m, int n)
{
    int i = 0, pos = 0, cnt = 0;
    initkmp(m);
    while (i < n)
    {
        while (pos != -1 && y[i] != x[pos])
            pos = kmp[pos];
        ++i, ++pos;
        if (pos >= m)
            ++cnt, pos = 0;
    }
    return cnt;
}

int main()
{
    while (scanf("%s", y), y[0] != '#')
    {
        scanf("%s", x);
        int m = strlen(x), n = strlen(y);
        printf("%d\n", KMP(m, n));
    }
    return 0;
}
