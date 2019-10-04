// POJ 3461
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10005;
int kmp[maxn];
char x[maxn], y[1000005];
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
            ++cnt, pos = kmp[pos];
    }
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", x, y);
        int m = strlen(x), n = strlen(y);
        printf("%d\n", KMP(m, n));
    }
    return 0;
}
