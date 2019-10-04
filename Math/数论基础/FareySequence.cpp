// POJ 2478
#include <iostream>
using namespace std;

const int maxn = 1e6 + 5;
int euler[maxn];

void euler_phi2()
{
    for (int i = 0; i < maxn; ++i)
        euler[i] = i;
    for (int i = 2; i < maxn; ++i)
        if (euler[i] == i)
        {
            for (int j = i; j < maxn; j += i)
                euler[j] = euler[j] / i * (i - 1);
        }
}

int main()
{
    int n;
    euler_phi2();
    while (cin >> n, n)
    {
        long long ans = 0;
        for (int i = 2; i <= n; ++i)
            ans += euler[i];
        cout << ans << endl;
    }
    return 0;
}