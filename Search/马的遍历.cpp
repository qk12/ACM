// Luogu 1443
#include <cstdio>
using namespace std;

const int MAXN = 500;

int n, m, x, y;
int mat[MAXN][MAXN];
int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool check(int a, int b)
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

void dfs(int a, int b, int depth)
{
    if (depth > 210)
        return;
    mat[a][b] = depth;
    for (int i = 0; i < 8; ++i)
    {
        int c = a + dir[i][0], d = b + dir[i][1];
        if (check(c, d) && (mat[c][d] < 0 || mat[c][d] > depth + 1))
            dfs(c, d, depth + 1);
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            mat[i][j] = -1;

    dfs(x - 1, y - 1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%-5d", mat[i][j]);
        putchar('\n');
    }
    return 0;
}