// URAL 1297
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110005;
char s[maxn], Ma[maxn << 1];
int Len[maxn << 1];
int Manacher(char s[], int len)
{
    int pos = 0;
    Ma[pos++] = '$';
    Ma[pos++] = '#';
    for (int i = 0; i < len; ++i)
        Ma[pos++] = s[i], Ma[pos++] = '#';
    Ma[pos] = 0;
    int mx = 0, mid = 0;
    for (int i = 0; i < pos; ++i)
    {
        Len[i] = (i < mx) ? min(Len[mid * 2 - i], mx - i) : 1;
        while (Ma[i + Len[i]] == Ma[i - Len[i]])
            ++Len[i];
        if (Len[i] + i > mx)
            mx = Len[i] + i, mid = i;
    }
    int ans = 0;
    for (int i = 0; i < 2 * len + 2; ++i)
        ans = max(ans, Len[i] - 1);
    return ans;
}

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    int ans = Manacher(s, len);
    int pos;
    for (pos = 0;; ++pos)
        if (Len[pos] - 1 == ans)
            break;
    int l = pos - ans, r = pos + ans;
    for (int i = l; i <= r; ++i)
        if (Ma[i] != '#')
            printf("%c", Ma[i]);
    printf("\n");
    return 0;
}