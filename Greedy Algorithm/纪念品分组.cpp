// Luogu 1094
#include <bits/stdc++.h>
using namespace std;

int a[30005];

int main()
{
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int x = 0, y = n - 1;
    int ans = 0;
    while (x <= y)
    {
        if (a[x] + a[y] <= w) //如果能装下，就装
            ++ans, ++x, --y;
        else //不能装下，将大的分为单独的一组
            --y, ++ans;
    }
    cout << ans << endl;
    return 0;
}