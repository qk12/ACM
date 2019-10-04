// POJ 2406
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000005;
int kmp[maxn];
char x[maxn];
int m;
void initkmp()
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
    while (scanf("%s", x))
    {
        if (x[0] == '.')
            break;
        m = strlen(x);
        initkmp();
        int ans = 1;
        if (m % (m - kmp[m]) == 0)
            ans = m / (m - kmp[m]);
        printf("%d\n", ans);
    }
    return 0;
}