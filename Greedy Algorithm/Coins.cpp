// HDU 3348
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int P, a, b, c, d, e;
    while (T--)
    {
        cin >> P >> a >> b >> c >> d >> e;
        int A = 0, B = 0;
        int sum = a + 5 * b + 10 * c + 50 * d + e * 100;
        int a1 = a, b1 = b, c1 = c, d1 = d, e1 = e;
        int sum2 = a + b + c + d + e;
        int temp = P;
        int temp2 = sum - P;
        while (temp >= 100 && e)
        {
            temp -= 100;
            ++A;
            e--;
        }
        while (temp >= 50 && d)
        {
            temp -= 50;
            ++A;
            d--;
        }
        while (temp >= 10 && c)
        {
            temp -= 10;
            ++A;
            c--;
        }
        while (temp >= 5 && b)
        {
            temp -= 5;
            ++A;
            b--;
        }
        while (temp >= 1 && a)
        {
            temp -= 1;
            ++A;
            a--;
        }

        while (temp2 >= 100 && e1)
        {
            temp2 -= 100;
            ++B;
            e1--;
        }
        while (temp2 >= 50 && d1)
        {
            temp2 -= 50;
            ++B;
            d1--;
        }
        while (temp2 >= 10 && c1)
        {
            temp2 -= 10;
            ++B;
            c1--;
        }
        while (temp2 >= 5 && b1)
        {
            temp2 -= 5;
            ++B;
            b1--;
        }
        while (temp2 >= 1 && a1)
        {
            temp2 -= 1;
            ++B;
            a1--;
        }

        if (temp != 0)
            cout << -1 << ' ';
        else
            cout << A << ' ';
        if (temp2 != 0)
            cout << -1 << endl;
        else
            cout << sum2 - B << endl;
    }
    return 0;
}