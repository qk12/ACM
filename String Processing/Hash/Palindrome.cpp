// URAL 1297
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
char s[maxn];
char Ma[maxn << 1];
int Len[maxn << 1];

void Manacher(char s[], int lens)
{
    int pos = 0;
    Ma[pos++] = '$';
    Ma[pos++] = '#';
    for (int i = 0; i < lens; i++)
    {
        Ma[pos++] = s[i];
        Ma[pos++] = '#';
    }
    Ma[pos] = 0;
    int mx = 0, mid = 0;
    for (int i = 0; i < pos; i++)
    {
        if (i < mx)
            Len[i] = min(Len[mid * 2 - i], mx - i);
        else
            Len[i] = 1;
        while (Ma[i + Len[i]] == Ma[i - Len[i]])
            Len[i]++;
        if (Len[i] + i > mx)
        {
            mx = Len[i] + i;
            mid = i;
        }
    }
}

int main()
{
    scanf("%s", s);
    int lens = strlen(s);
    Manacher(s, lens);
    int ans = 0;
    for (int i = 0; i < 2 * lens + 2; i++)
        ans = max(ans, Len[i] - 1);
    int i;
    for (i = 0;; ++i)
        if (Len[i] - 1 == ans)
            break;
    if (ans & 1)
        i -= (ans / 2) * 2;
    else
        i -= (ans / 2) * 2 - 1;
    while (ans--)
    {
        printf("%c", Ma[i]);
        i += 2;
    }
    printf("\n");
    return 0;
}