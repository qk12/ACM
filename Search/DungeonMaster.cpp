// POJ 2251
#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
struct node
{
    int x, y, z;
    int depth;
};
char mat[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int n, m, h;
int sx, sy, sz;
int fx, fy, fz;
int dir[6][3] = {{0, 1, 0}, {0, -1, 0}, {-1, 0, 0}, {1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

inline bool check(int a, int b, int c)
{
    return 0 <= a && a < n && 0 <= b && b < m && 0 <= c && c < h;
}
int bfs()
{
    queue<node> q;
    node s{sx, sy, sz, 0};
    q.push(s);
    vis[sz][sx][sy] = true;
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        if (temp.x == fx && temp.y == fy && temp.z == fz)
            return temp.depth;
        for (int i = 0; i < 6; ++i)
        {
            s.x = temp.x + dir[i][0], s.y = temp.y + dir[i][1], s.z = temp.z + dir[i][2];
            s.depth = temp.depth + 1;
            if (check(s.x, s.y, s.z) && !vis[s.x][s.y][s.z] && mat[s.x][s.y][s.z] != '#')
            {
                q.push(s);
                vis[s.x][s.y][s.z] = true;
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> h >> n >> m)
    {
        if (h + n + m == 0)
            break;
        //读入mat矩阵时要特别注意循环顺序
        for (int k = 0; k < h; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    cin >> mat[i][j][k];
                    if (mat[i][j][k] == 'S')
                        sx = i, sy = j, sz = k;
                    if (mat[i][j][k] == 'E')
                        fx = i, fy = j, fz = k;
                }
        int ans = bfs();
        if (ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}