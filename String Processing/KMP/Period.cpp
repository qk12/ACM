// HDU 1358
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
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
    int m, kase = 0;
    while (scanf("%d", &m), m)
    {
        scanf("%s", x);
        initkmp(m);
        printf("Test case #%d\n", ++kase);
        for (int i = 2; i <= m; i++)
            if (kmp[i] != 0 && i % (i - kmp[i]) == 0)
                printf("%d %d\n", i, i / (i - kmp[i]));
        printf("\n");
    }
    return 0;
}