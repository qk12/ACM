// HYSBZ 1257
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long ans = (long long)n * k;
    if (n > k)
        n = k;
    int l, r, j;
    for (int i = 1; i <= n; i = r + 1)
    {
        j = k / i;
        l = k / (j + 1) + 1;
        r = k / j;
        if (r >= n)
            r = n;
        ans -= (long long)(l + r) * (r - l + 1) * j / 2;
    }
    cout << ans << endl;
    return 0;
}