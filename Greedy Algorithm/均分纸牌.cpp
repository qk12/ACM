// Luogu 1031
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int average = sum / n;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != average)
        {
            a[i + 1] = a[i + 1] + a[i] - average;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}