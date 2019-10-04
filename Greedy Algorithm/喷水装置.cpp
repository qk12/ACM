// ybt 1424
#include <bits/stdc++.h>
using namespace std;

pair<double, double> a[15005];

int main()
{
    int T;
    cin >> T;
    int n, L;
    double W;
    while (T--)
    {
        cin >> n >> L >> W;
        int x;
        double r;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> r;
            if (r < W / 2)
                continue;
            r = sqrt(r * r - (W / 2) * (W / 2));
            a[cnt].first = x - r;
            a[cnt].second = x + r;
            ++cnt;
        }
        sort(a, a + cnt); //左端点非递减，若左端相同则右端点非递减（其实右端点怎样排序无所谓）

        int i = 0, ans = 0;
        double t = 0; //t是已灌溉区域的右端点
        bool flag = true;
        while (i < cnt)
        {
            if (t < a[i].first) //中间有一段不能完全覆盖
            {
                flag = false;
                break;
            }
            if (t >= L) //已经完全覆盖
                break;
            double max_r = -1;
            while (i < cnt && a[i].first <= t) //在可选范围中选取右端点最大的
            {
                max_r = max(max_r, a[i].second);
                ++i;
            }
            t = max_r;
            ++ans;
        }
        if (flag)
            cout << ans << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}