// POJ 2960
#include <cstdio>
#include <set>
using namespace std;

const int maxn = 105;
int s[maxn];
int a[maxn];
int sg[10005];

void SG(int n, int k)
{
    sg[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        set<int> S;
        for (int j = 0; j < k; ++j)
        {
            S.insert(sg[i - s[j]]);
        }
        int g = 0;
        while (S.count(g) != 0)
            ++g;
        sg[i] = g;
    }
}

int main()
{
    int k, m, n;
    while (scanf("%d", &k), k)
    {
        for (int i = 0; i < k; ++i)
            scanf("%d", s + i);
        SG(10000, k);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &n);
            int res = 0;
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", a + j);
                res ^= sg[a[j]];
            }
            if (res == 0)
                printf("%c", 'L');
            else
                printf("%c", 'W');
        }
        printf("\n");
    }
    return 0;
}