#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int temp = min(r, min(g, b));
    long long cnt = 0;
    cnt += temp;
    int x = 0;
    r -= temp, g -= temp, b -= temp;
    if (r % 3 == 2)
        x++;
    if (g % 3 == 2)
        x++;
    if (b % 3 == 2)
        x++;
    if (x >= 2 && cnt > 0)
    {
        cnt--;
        cnt += (r + 1) / 3 + (g + 1) / 3 + (b + 1) / 3;
    }
    else
        cnt += r / 3 + g / 3 + b / 3;
    cout << cnt << endl;
    return 0;
}