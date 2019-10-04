// Large Division
// LightOJ 1214

#include <cstdio>
#include <cstring>
using namespace std;

char s[205];
int main()
{
    int T;
    long long a, b;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        scanf("%s%lld", s, &b);
        int len = strlen(s);
        a = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '-')
                continue;
            a = (a * 10 + s[i] - '0') % b;
        }
        if (a == 0)
            printf("Case %d: divisible\n", k);
        else
            printf("Case %d: not divisible\n", k);
    }
    return 0;
}