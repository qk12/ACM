// POJ 1328
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

pair<double, double> a[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double d;
    int kase = 0;
    while (cin >> n >> d)
    {
        if (n == 0 || d == 0)
            break;
        cout << "Case " << ++kase << ": ";
        bool flag = true;
        int x, y;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x >> y;
            double dis = sqrt(d * d - y * y);
            a[i].second = x - dis, a[i].first = x + dis;
            if (y > d)
                flag = false;
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            sort(a + 1, a + 1 + n);
            int ans = 1;
            double t = a[1].first;
            for (int i = 2; i <= n; ++i)
            {
                if (a[i].second > t)
                {
                    ans++;
                    t = a[i].first;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
