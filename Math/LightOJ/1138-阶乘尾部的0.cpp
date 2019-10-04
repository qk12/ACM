#include <iostream>
using namespace std;

int Zero(int n)
{
    int res = 0;
    while (n)
    {
        res += n / 5;
        n /= 5;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n;
    for (int k = 1; k <= T; ++k)
    {
        cout << "Case " << k << ": ";
        cin >> n;
        int l = 4, r = 420000000;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (Zero(m) < n)
                l = m + 1;
            else
                r = m;
        }
        if (Zero(l) == n)
            cout << l << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}