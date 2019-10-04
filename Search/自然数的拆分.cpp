// Luogu 2404
#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
int path[maxn];
int n, cnt;

void dfs(int depth, int state, int last)
{
    if (state > n)
        return;
    if (state == n)
    {
        cnt++;
        cout << n << '=';
        for (int i = 1; i < depth; ++i)
            cout << path[i] << '+';
        cout << path[depth] << endl;
        return;
    }
    else
    {
        for (int i = last; i < n; ++i)
        {
            path[depth + 1] = i;
            dfs(depth + 1, state + i, i);
        }
    }
}

int main()
{
    cin >> n;
    dfs(0, 0, 1);
    return 0;
}