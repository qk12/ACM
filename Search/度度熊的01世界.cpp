// HDU 6113
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
char mat[maxn][maxn]; //矩阵
int n, m;             //边界
int idx[maxn][maxn];
int f[maxn * maxn];                                 //映射查找数组
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //东南西北方向对应于行数i和列数j的变化
int cnt;                                            //cnt为每个连通块包含的格子个数

inline bool check(int a, int b) //检查边界
{
    return 0 <= a && a <= n + 1 && 0 <= b && b <= m + 1;
}

void dfs(int a, int b, int id, char x)
{
    idx[a][b] = id;
    for (int i = 0; i < 4; ++i)
    {
        int c = a + dir[i][0], d = b + dir[i][1];
        if (check(c, d) && idx[c][d] == 0 && mat[c][d] == x) //未出界的格子、未访问过的格子
            dfs(c, d, id, x);
    }
    ++cnt;
}

int solve(char x) //返回连通块的数量
{
    memset(idx, 0, sizeof(idx));
    int id = 0; //id为连通分量编号，从1开始，同一个连通块的格子的编号相同
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j)
            if (idx[i][j] == 0 && mat[i][j] == x)
            {
                cnt = 0;
                dfs(i, j, ++id, x);
                f[idx[i][j]] = cnt;
            }
    return id; //最终id数即为连通块的数量
}

int main()
{
    while (cin >> n >> m)
    {
        //不能用memset(mat, 0, sizeof(mat));  '0'!='\0'
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < maxn; ++j)
                mat[i][j] = '0';

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> mat[i][j];
        int cnt0 = solve('0');
        int cnt1 = solve('1');
        if (cnt0 == 2 && cnt1 == 1)
            cout << 0 << endl;
        else if (cnt0 == 1 && cnt1 == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}