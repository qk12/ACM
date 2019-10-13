// HDU 3746
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int kmp[maxn];
char x[maxn];
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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", x);
        int len = strlen(x);
        initkmp(len);
        int t = len - kmp[len];
        if (len % t == 0 && kmp[len] != 0)
            printf("0\n");
        else
            printf("%d\n", t - len % t);
    }
    return 0;
}