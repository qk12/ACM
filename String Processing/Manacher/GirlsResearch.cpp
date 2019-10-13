// HDU 3294
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
char s[maxn], Ma[maxn << 1];
int Len[maxn << 1];
void Manacher(char s[], int len)
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
        if (Len[i] - 1 > ans)
            ans = Len[i] - 1, pos = i;
    if (ans < 2)
    {
        printf("No solution!\n");
        return;
    }
    int l = (pos - ans + 1) / 2 - 1, r = (pos + ans - 1) / 2 - 1;
    printf("%d %d\n", l, r);
    for (int i = l; i <= r; ++i)
        printf("%c", s[i]);
    printf("\n");
}

int main()
{
    char ch;
    while (cin >> ch)
    {
        scanf("%s", s);
        int len = strlen(s);
        int x = ch - 'a';
        for (int i = 0; i < len; ++i)
            s[i] = (s[i] - 'a' - x + 26) % 26 + 'a';
        Manacher(s, len);
    }
    return 0;
}