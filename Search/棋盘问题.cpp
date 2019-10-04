// POJ 1321
#include <iostream>
using namespace std;

char mat[10][10];
bool vis[10];
int n, k, cnt;

void dfs(int depth, int state)
{
    if (depth == n)
    {
        if (state == k)
            ++cnt;
        return;
    }
    for (int j = 0; j < n; ++j)
    {
        if (!vis[j] && mat[depth][j] == '#')
        {
            vis[j] = true;
            dfs(depth + 1, state + 1);
            vis[j] = false;
        }
    }
    dfs(depth + 1, state);
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == -1 && k == -1)
            break;
        cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> mat[i][j];
        dfs(0, 0);
        cout << cnt << endl;
    }
    return 0;
}
