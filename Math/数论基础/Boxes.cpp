// URAL 1114
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int c = max(a, b);
    --n;

    LL ans = 1, tmp = 1, sum = 1;
    for (int i = 1; i <= c; i++)
    {
        tmp = tmp * (n + i) / i;
        sum += tmp;

        if (i == a)
            ans *= sum;
        if (i == b)
            ans *= sum;
    }

    cout << ans << endl;
    return 0;
}