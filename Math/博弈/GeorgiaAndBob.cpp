// POJ 1704
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1005;
int a[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (n % 2 == 1)
            a[n++] = 0;
        sort(a, a + n);
        int res = 0;
        for (int i = 1; i < n; i += 2)
            res ^= (a[i] - a[i - 1] - 1);
        if (res == 0)
            cout << "Bob will win" << endl;
        else
            cout << "Georgia will win" << endl;
    }
    return 0;
}
