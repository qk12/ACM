// HYSBZ 3676
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;
struct Palindromic_Tree
{
    int ch[maxn][26], f[maxn], len[maxn], s[maxn];
    ll cnt[maxn];
    int last, sz, n;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] = 0, len[sz] = x;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n])
            u = f[u];
        return u;
    }
    void add(int c)
    { // c-='a'
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
        }
        last = ch[u][c];
        ++cnt[last];
    }
    ll query()
    {
        for (int i = sz - 1; i >= 0; --i)
            cnt[f[i]] += cnt[i];
        ll ans = 0;
        for (int i = 2; i < sz; ++i)
            ans = max(ans, (ll)cnt[i] * len[i]);
        return ans;
    }
} pam;

char s[maxn];
int main()
{
    pam.init();
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        pam.add(s[i] - 'a');
    printf("%lld\n", pam.query());
    return 0;
}