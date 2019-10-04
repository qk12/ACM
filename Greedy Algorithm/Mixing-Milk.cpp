// Luogu 1208
#include <bits/stdc++.h>
using namespace std;

struct former
{
    int P, A;
} s[5005];
bool cmp(former &a, former &b)
{
    if (a.P != b.P)
        return a.P < b.P;
    else
        return a.A > b.A;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> s[i].P >> s[i].A;
    }
    sort(s, s + m, cmp);
    long long ans = 0;
    int i = 0;
    while (n)
    {
        if (s[i].A != 0) //当这头牛还没购买完
        {
            --s[i].A;      //这头牛可购买数减一
            ans += s[i].P; //总花费加上这头牛的单价（或者说当前最小单价）
            --n;           //需求量减一
        }
        else
            ++i; //购买完了换头牛
    }
    cout << ans << endl;
    return 0;
}