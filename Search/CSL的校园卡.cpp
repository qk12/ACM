// Gym 224647M
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 5;

struct node
{
    int x, y, x2, y2;
    int state;
    int depth;
};

char mat[maxn][maxn];
bool vis[maxn][maxn][maxn][maxn][1 << 16];
int n, m, k;
int sx, sy, fx, fy; //终点坐标
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int S, ans;

inline bool check(int a, int b)
{
    return 0 <= a && a < n && 0 <= b && b < m;
}

void bfs()
{
    queue<node> que; //bfs用队列
    que.push(node{sx, sy, sx, sy, 1 << (sx * m + sy), 0});
    vis[sx][sy][sx][sy][1 << (sx * m + sy)] = true;
    while (que.size())
    {
        node p = que.front();
        que.pop();
        if (p.state == S)
        {
            ans = p.depth;
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int a = p.x + dir[i][0], b = p.y + dir[i][1];
            if (!check(a, b) || mat[a][b] == 'X')
                continue;
            for (int j = 0; j < 4; ++j)
            {
                int c = p.x2 + dir[j][0], d = p.y2 + dir[j][1];
                int s = p.state | (1 << (a * m + b)) | (1 << (c * m + d));
                if (check(c, d) && !vis[a][b][c][d][s] && mat[a][b] != 'X')
                {
                    que.push(node{a, b, c, d, s, p.depth + 1});
                    vis[a][b][c][d][s] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'O')
                S |= 1 << (i * m + j);
            else if (mat[i][j] == 'S')
            {
                sx = i, sy = j;
                S |= 1 << (i * m + j);
            }
        }
    bfs();
    cout << ans << endl;
    return 0;
}