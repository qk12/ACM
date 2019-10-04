// POJ 2752
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 400005;
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
    int T;
    scanf("%d", &T);
    while (scanf("%s", x) != EOF)
    {
        vector<int> ans;
        int m = strlen(x);
        initkmp(m);
        int pos = kmp[m];
        while (pos > 0)
        {
            ans.push_back(pos);
            pos = kmp[pos];
        }
        for (int i = ans.size() - 1; i >= 0; --i)
            printf("%d ", ans[i]);
        printf("%d\n", m);
        //for (int i = 1; i <= m; ++i)
        //printf("%d ", kmp[i]);
        printf("\n");
    }
    return 0;
}
