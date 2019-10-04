// Luogu 1250
#include <iostream>
using namespace std;

struct line
{
    int s, e, v;
} a[5005];

bool cmp(line &x, line &y)
{
    if (x.e != y.e)
        return x.e < y.e;
    else
        return x.s > y.s;
}

int n, m;
bool vis[30005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].s >> a[i].e >> a[i].v;
    sort(a + 1, a + 1 + m, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++) //依次处理m个区间
    {
        int k = 0;
        for (int j = a[i].s; j <= a[i].e; j++)
            if (vis[j])
                k++; //统计区间内已标记的数
        if (k < a[i].v)
            for (int j = a[i].e; j >= a[i].s; j--)
                if (!vis[j])
                {
                    vis[j] = true;
                    k++;
                    ans++;
                    if (k == a[i].v)
                        break;
                }
    }
    cout << ans << endl;
    return 0;
}