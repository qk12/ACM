// Luogu 1434
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n, m;
int mat[maxn][maxn];
int dp[maxn][maxn];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //方向数组

inline bool check(int a, int b) { return a >= 0 && a < n && b >= 0 && b < m; }
int dfs(int a, int b) //求到(a,b)点的最长路径
{
    if (dp[a][b] > 0)
        return dp[a][b];
    int res = 1;
    for (int i = 0; i < 5; i++)
    {
        int c = a + dir[i][0], d = b + dir[i][1];
        if (check(c, d) && (mat[a][b] < mat[c][d]))
            res = max(res, dfs(c, d) + 1);
    }
    return dp[a][b] = res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++) //按照行的顺序，利用递归逐点求出区域中到达此点的最长路径
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}
