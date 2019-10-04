// Luogu 1248
#include <iostream>
using namespace std;

struct node
{
    int first;
    int second;
    int id;
} a[10005];

bool cmp(node &x, node &y)
{
    if (min(x.first, y.second) == min(x.second, y.first))
        return x.first == y.first ? x.second < y.second : x.first < y.first;
    else
        return min(x.first, y.second) < min(x.second, y.first);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].id = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].second;
    }
    sort(a + 1, a + 1 + n, cmp);
    int x = a[1].first;
    int y = a[1].first + a[1].second;
    for (int i = 2; i <= n; ++i)
    {
        y = max(x + a[i].first, y) + a[i].second;
        x += a[i].first;
    }
    cout << y << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
            cout << a[i].id;
        else
            cout << ' ' << a[i].id;
    }
    return 0;
}