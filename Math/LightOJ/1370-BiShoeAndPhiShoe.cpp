#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1e6 + 5;
int euler[maxn];
void euler_phi2(int n) //筛出欧拉函数值的表
{
    for (int i = 0; i <= n; ++i)
        euler[i] = i;
    for (int i = 2; i <= n; ++i)
        if (euler[i] == i)
            for (int j = i; j <= n; j += i)
                euler[j] = euler[j] / i * (i - 1);
}

int a[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    euler_phi2(maxn);
    int T;
    cin >> T;
    int n;
    for (int k = 1; k <= T; ++k)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        int i = 1, j = 2;
        while (i <= n)
        {
            if (a[i] <= euler[j])
            {
                ans += j;
                ++i;
            }
            else
                ++j;
        }
        cout << "Case " << k << ": " << ans << " Xukha" << endl;
    }
    return 0;
}