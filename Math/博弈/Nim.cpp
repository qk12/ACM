// POJ 2975
#include <iostream>
using namespace std;

int a[1005];
int main()
{
    int n;
    while (cin >> n, n)
    {
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            res ^= a[i];
        }
        if (res == 0)
            cout << 0 << endl;
        else
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] > (res ^ a[i]))
                    ++cnt;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}