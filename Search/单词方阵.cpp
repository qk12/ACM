// Luogu 1101
#include <iostream>
#include <string>
using namespace std;

const int maxn = 105;
const string s = "yizhong";
char mat[maxn][maxn]; //矩阵
pair<int, int> path[maxn];
bool vis[maxn][maxn];
int n, m; //边界
int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

inline bool check(int a, int b) //检查边界
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

void dfs(int a, int b, int k, int depth) //当前位置、当前状态
{
    path[depth].first = a, path[depth].second = b;
    if (depth == 6) //递归边界
    {
        for (int i = 0; i < 7; ++i)
            vis[path[i].first][path[i].second] = true;
        return;
    }
    else
    {
        int c = a + dir[k][0], d = b + dir[k][1];
        if (check(c, d) && mat[c][d] == s[depth + 1])
        {
            dfs(c, d, k, depth + 1);
        }
    }
}

int main()
{
    cin >> n;
    m = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (mat[i][j] == 'y')
            {
                for (int k = 0; k < 8; ++k)
                {
                    int c = i + dir[k][0], d = j + dir[k][1];
                    if (check(c, d) && mat[c][d] == s[1])
                        dfs(i, j, k, 0);
                }
            }
        }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (vis[i][j])
                cout << mat[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
    return 0;
}