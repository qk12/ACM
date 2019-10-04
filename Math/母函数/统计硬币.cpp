// HDU 2566
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n, m;
    while (T--)
    {
        cin >> n >> m;
        int cnt = 0;
        for (int i = 0; i <= n; ++i)     //1
            for (int j = 0; j <= n; ++j) //2
            {
                int temp = i + 2 * j;
                if (temp <= m && (m - temp) % 5 == 0)
                {
                    int k = (m - temp) / 5;
                    if (i + j + k == n)
                        ++cnt;
                }
            }
        cout << cnt << endl;
    }
    return 0;
}