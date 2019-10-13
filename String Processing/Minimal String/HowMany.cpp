// HDU 2609
#include <bits/stdc++.h>
using namespace std;

void minimal_string(char s[], int len, char t[])
{
    int i = 0, j = 1, k = 0;
    while (k < len && i < len && j < len)
    {
        int temp = s[(i + k) % len] - s[(j + k) % len];
        if (temp == 0)
            ++k;
        else
        {
            if (temp > 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                ++i;
            k = 0;
        }
    }
    int id = min(i, j);
    for (int p = 0; p < len; ++p)
        t[p] = s[(id + p) % len];
    t[len] = '\0';
}

char s[105], t[105];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        set<string> S;
        while (n--)
        {
            scanf("%s", s);
            int len = strlen(s);
            minimal_string(s, len, t);
            S.insert(t);
        }
        printf("%d\n", (int)S.size());
    }
    return 0;
}