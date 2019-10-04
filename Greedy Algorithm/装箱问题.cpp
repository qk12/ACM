// ybt 1226
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    int base[4] = {0, 5, 3, 1};
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        if (a + b + c + d + e + f == 0)
            break;
        int ans = f + e + d + (c + 3) / 4;
        int x = 5 * d + base[c % 4];
        if (b > x)
            ans += (b - x + 8) / 9;
        int y = 36 * ans - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        if (a > y)
            ans += (a - y + 35) / 36;
        cout << ans << endl;
    }
    return 0;
}