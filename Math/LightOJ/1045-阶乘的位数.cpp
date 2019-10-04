#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
double s[maxn];

void init()
{
    s[0] = 0;
    for (int i = 1; i < maxn; ++i)
        s[i] = s[i - 1] + log(i);
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        int n, base;
        scanf("%d%d", &n, &base);
        ll ans = (ll)(s[n] / log(base) + 1);
        printf("Case %d: %lld\n", k, ans);
    }
    return 0;
}