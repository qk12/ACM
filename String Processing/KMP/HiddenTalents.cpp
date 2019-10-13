// HDU 2594
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
    while (scanf("%s", x) != EOF)
    {
        int len1 = strlen(x);
        scanf("%s", x + len1);
        int len2 = strlen(x);
        initkmp(len2);
        int ans = kmp[len2];
        //kmp数组求得的数据，前缀有可能包含了s2，后缀有可能包含了s1
        //所以应该是对kmp数组不断进行递归，直到ans小于其中两者小的的长度;
        while (ans > len1 || ans > len2 - len1)
        {
            ans = kmp[ans];
        }
        if (ans == 0 || ans == -1)
        {
            printf("%d\n", ans);
            continue;
        }
        for (int i = 0; i < ans; ++i)
            printf("%c", x[i]);
        printf(" %d\n", ans);
    }
    return 0;
}