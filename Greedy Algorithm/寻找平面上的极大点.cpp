// Luogu 2772
#include <iostream>
using namespace std;

typedef pair<int, int> P;
const int maxn = 500005;
P a[maxn];
int temp[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    int y = 0;
    int cnt = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i].second > y)
        {
            temp[cnt++] = i;
            y = a[i].second;
        }
    }
    for (int i = cnt - 1; i >= 0; --i)
    {
        if (i == cnt - 1)
            cout << '(' << a[temp[i]].first << ',' << a[temp[i]].second << ')';
        else
            cout << ",(" << a[temp[i]].first << ',' << a[temp[i]].second << ')';
    }
    return 0;
}