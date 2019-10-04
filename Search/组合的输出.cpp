// Luogu 1157
#include <bits/stdc++.h>
using namespace std;

bool vis[25];
int path[25];
int n, r;

void dfs(int depth, int state)
{
    if (depth == r)
    {
        for (int i = 1; i <= r; i++)
            printf("%3d", path[i]);
        printf("\n");
    }
    else
    {
        for (int i = state + 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                path[depth + 1] = i;
                vis[i] = true;
                dfs(depth + 1, i);
                vis[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &r);
    dfs(0, 0);
    return 0;
}
