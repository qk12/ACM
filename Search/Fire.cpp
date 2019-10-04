// UVA 11624
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct Node
{
    int x, y, depth;
};
char mat[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int n, m;           //边界
int sx, sy, fx, fy; //起始坐标和终点坐标
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
queue<Node> que;

inline bool check(int a, int b) { return 0 <= a && a < n && 0 <= b && b < m; }
void init_bfs()
{
    while (!que.empty())
    {
        Node p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = p.x + dir[i][0], b = p.y + dir[i][1];
            if (check(a, b) && mat[a][b] != '#' && dis[a][b] == INF)
            {
                que.push(Node{a, b, 0});
                dis[a][b] = dis[p.x][p.y] + 1;
            }
        }
    }
}
int bfs()
{
    while (!que.empty())
        que.pop();
    que.push(Node{sx, sy, 0});
    vis[sx][sy] = true;
    while (que.size()) //不断循环直到队列的长度为0
    {
        Node p = que.front(); //从队列的最前端取出元素
        que.pop();
        if (p.x == 0 || p.x == n - 1 || p.y == 0 || p.y == m - 1) //如果取出的状态已经是终点，则结束搜索
            return p.depth + 1;
        for (int i = 0; i < 4; ++i)
        {
            int a = p.x + dir[i][0], b = p.y + dir[i][1]; //移动之后的位置记为(a,b)
            if (check(a, b) && !vis[a][b] && mat[a][b] != '#' && p.depth + 1 < dis[a][b])
            {
                que.push(Node{a, b, p.depth + 1}); //不能用mat[][]=='.'，否则无法访问终点（终点不是'.'）
                vis[a][b] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        while (!que.empty())
            que.pop();
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'J')
                    sx = i, sy = j;
                if (mat[i][j] == 'F')
                {
                    que.push(Node{i, j, 0});
                    dis[i][j] = 0;
                }
            }
        init_bfs();
        int ans = bfs();
        if (ans == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}