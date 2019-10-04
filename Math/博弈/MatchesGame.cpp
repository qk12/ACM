// POJ 2234
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int res = 0, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            res ^= x;
        }
        if (res != 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}