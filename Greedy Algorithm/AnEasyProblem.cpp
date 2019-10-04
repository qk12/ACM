// ybt 1223
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int cnt = 0;
        int temp = n;
        while (temp > 0)
        {
            if (temp % 2)
                cnt++;
            temp /= 2;
        }
        int sum = 0;
        while (1)
        {
            temp = ++n;
            while (temp > 0)
            {
                if (temp % 2)
                    sum++;
                temp /= 2;
            }
            if (cnt == sum)
            {
                cout << n << endl;
                break;
            }
            sum = 0;
        }
    }
    return 0;
}