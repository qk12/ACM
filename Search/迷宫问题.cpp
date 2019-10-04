// POJ 3984
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 8;
const int INF = 1005;
typedef pair<int, int> P;

int mat[maxn][maxn];
int dis[maxn][maxn];
int n, m;
int sx, sy, fx, fy;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

P q[maxn][maxn];

void output(int x, int y)
{
    if (x == -1 && y == -1)
        return;
    output(q[x][y].first, q[x][y].second);
    printf("(%d, %d)\n", x, y);
}

inline bool check(int a, int b) { return 0 <= a && a < n && 0 <= b && b < m; }
int bfs()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dis[i][j] = INF;

    queue<P> que;
    que.push(P{sx, sy});
    dis[sx][sy] = 0;
    q[sx][sy] = {-1, -1};
    while (que.size())
    {
        P p = que.front();
        que.pop();
        if (p.first == fx && p.second == fy)
        {
            output(fx, fy);
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int a = p.first + dir[i][0], b = p.second + dir[i][1];
            if (check(a, b) && dis[a][b] == INF && mat[a][b] != 1)
            {
                que.push(P(a, b));
                dis[a][b] = dis[p.first][p.second] + 1;
                q[a][b] = {p.first, p.second};
            }
        }
    }
    return dis[fx][fy]; //若返回INF则表示无解
}

int main()
{
    n = 5, m = 5;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &mat[i][j]);
    sx = 0, sy = 0, fx = 4, fy = 4;
    bfs();
    return 0;
}