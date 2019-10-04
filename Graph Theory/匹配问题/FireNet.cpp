// HDU 1045
#include <bits/stdc++.h>
using namespace std;

int n, ans;
char maze[5][5];

bool check(int r, int c)
{
    for (int i = r; i >= 0; i--)
    {
        if (maze[i][c] == '0')
            return false;
        if (maze[i][c] == 'X')
            break;
    }
    for (int j = c; j >= 0; j--)
    {
        if (maze[r][j] == '0')
            return false;
        if (maze[r][j] == 'X')
            break;
    }
    return true;
}

void dfs(int i, int num)
{
    if (i == n * n)
    {
        ans = max(ans, num);
        return;
    }
    int r = i / n;
    int c = i % n;
    if (maze[r][c] == '.' && check(r, c))
    {
        maze[r][c] = '0';
        dfs(i + 1, num + 1);
        maze[r][c] = '.';
    }
    dfs(i + 1, num);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n, n)
    {
        ans = 0;
        for (int i = 0; i < n; ++i)
            cin >> maze[i];
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}