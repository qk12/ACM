// UVA 1600
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
const int INF = 0x3f3f3f3f;

struct node
{
    int x, y, state;
};

int mat[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn][maxn];
int n, m, k;
int sx, sy, fx, fy; //终点坐标
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

inline bool check(int a, int b, int state)
{
    return 0 <= a && a < n && 0 <= b && b < m && state <= k;
}

int bfs()
{
    for (int i = 0; i < n; ++i) //初始化所有距离为极大
        for (int j = 0; j < m; ++j)
            dis[i][j] = INF;

    queue<node> que; //bfs用队列
    que.push(node{sx, sy, 0});
    vis[sx][sy][0] = true;
    dis[sx][sy] = 0;
    while (que.size())
    {
        node p = que.front();
        que.pop();
        if (p.x == fx && p.y == fy)
            break;
        for (int i = 0; i < 4; ++i)
        {
            int a = p.x + dir[i][0], b = p.y + dir[i][1]; //移动之后的位置记为(a,b)
            int c = p.state;
            if (mat[a][b] == 1)
                c++;
            else if (mat[a][b] == 0)
                c = 0;
            if (check(a, b, c) && !vis[a][b][c]) //判断是否超出边界、是否访问过、是否可以访问
            {
                que.push(node{a, b, c});
                vis[a][b][c] = true;
                dis[a][b] = dis[p.x][p.y] + 1;
            }
        }
    }
    return dis[fx][fy]; //若返回INF则表示无解
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> mat[i][j];
        sx = 0, sy = 0, fx = n - 1, fy = m - 1;
        int ans = bfs();
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}