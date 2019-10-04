// HDU 1016
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int a[maxn];
bool vis[maxn];
int n;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(int cur)
{
    if (cur == n && isPrime(a[1] + a[n]))
    {
        for (int i = 1; i < n; i++)
            cout << a[i] << ' ';
        cout << a[n] << endl;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i] && isPrime(i + a[cur]))
            {
                a[cur + 1] = i;
                vis[i] = true;
                dfs(cur + 1);
                vis[i] = false;
            }
        }
    }
}

int main()
{
    int kase = 0;
    while (cin >> n)
    {
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++)
            a[i] = i;
        cout << "Case " << ++kase << ':' << endl;
        dfs(1);
        cout << endl;
    }
    return 0;
}