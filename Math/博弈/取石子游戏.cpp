// POJ 1067
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        if (x > y)
            swap(x, y);
        int z = y - x;
        int w = int((sqrt(5) + 1) / 2 * z);
        if (x == w)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
