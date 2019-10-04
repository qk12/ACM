// POJ 3480
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, res = 0, maxx = 0, x;
        cin >> n;
        while (n--)
        {
            cin >> x;
            maxx = max(maxx, x);
            res ^= x;
        }
        if ((res != 0 && maxx > 1) || (res == 0 && maxx == 1))
            puts("John");
        else
            puts("Brother");
    }
    return 0;
}