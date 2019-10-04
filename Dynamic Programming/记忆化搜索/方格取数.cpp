// Luogu 2774
#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
const int minINF = 0xc0c0c0c0;
int mat[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int dir[2][2] = {{0, 1}, {1, 0}};
int n;

bool check(int a, int b, int c, int d)
{
    return a <= n && b <= n && c <= n && d <= n;
}

int dfs(int x, int y, int x2, int y2) //两种方案同时执行，表示当第一种方案走到x,y,第二种方案走到x2,y2时到终点取得的最大数
{
    if (dp[x][y][x2][y2] != minINF)
        return dp[x][y][x2][y2];
    int res = 0;
    for (int i = 0; i < 2; ++i)
    {
        int a = x + dir[i][0], b = y + dir[i][1];
        for (int j = 0; j < 2; ++j)
        {
            int c = x2 + dir[j][0], d = y2 + dir[j][1];
            if (check(a, b, c, d))
                res = max(res, dfs(a, b, c, d));
        }
    }
    res += (mat[x][y] == mat[x2][y2] ? mat[x][y] : mat[x][y] + mat[x2][y2]);
    return dp[x][y][x2][y2] = res;
}

int main()
{
    cin >> n;
    memset(dp, 0xc0, sizeof(dp));
    int x, y, v;
    while (cin >> x >> y >> v)
    {
        if (x == 0 && y == 0 && v == 0)
            break;
        mat[x][y] = v;
    }
    dp[n][n][n][n] = mat[n][n];
    cout << dfs(1, 1, 1, 1) << endl; //输出，因为dfs中没有考虑第一格，即s[1][1]，所以最后要加一下
    return 0;
}
