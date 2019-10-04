// POJ 2348
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 || b == 0)
            break;
        bool flag = true;
        while (true)
        {
            if (a > b)
                swap(a, b);
            if (b % a == 0)
                break;
            if (b - a > a)
                break;
            b -= a;
            flag = !flag;
        }
        if (flag)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}