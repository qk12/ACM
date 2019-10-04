// HDU 1160
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int dp[maxn], path[maxn];

struct node
{
    int w, s, id;
} m[maxn];

bool cmp(const node &x, const node &y)
{
    if (x.w == y.w)
        return x.s > y.s;
    return x.w < y.w;
}

void output(int x)
{
    if (x == -1)
        return;
    output(path[x]);
    printf("%d\n", x + 1);
}

int main()
{
    int cnt = 0;
    int w, s;
    while (scanf("%d%d", &w, &s) != EOF)
    {
        m[cnt].w = w, m[cnt].s = s, m[cnt].id = cnt;
        ++cnt;
    }
    sort(m, m + cnt, cmp);
    memset(path, -1, sizeof(path));
    int ans = 0, id;
    for (int i = 0; i < cnt; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (m[j].w < m[i].w && m[j].s > m[i].s && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                path[m[i].id] = m[j].id;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            id = m[i].id;
        }
    }
    printf("%d\n", ans);
    output(id);
    return 0;
}