// HDU 3374
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
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

int min_max_express(char s[], int len, bool flag)
{
    int i = 0, j = 1, k = 0;
    while (k < len && i < len && j < len)
    {
        int temp = s[(i + k) % len] - s[(j + k) % len];
        if (temp == 0)
            ++k;
        else
        {
            if ((flag ? temp > 0 : temp <= 0)) //最大表示法：if (temp <= 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                ++i;
            k = 0;
        }
    }
    int id = min(i, j);
    return id;
}

int main()
{
    while (scanf("%s", s) != EOF)
    {
        int len = strlen(s);
        int id1 = min_max_express(s, len, true);
        int id2 = min_max_express(s, len, false);
        initkmp(s, len);
        int l = len - kmp[len];
        int ans = (len % l == 0 ? len / l : 1);
        printf("%d %d %d %d\n", id1 + 1, ans, id2 + 1, ans);
    }
    return 0;
}