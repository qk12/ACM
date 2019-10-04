// HDU 1429
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int n, m, t;
char mat[maxn][maxn];
int sx, sy, fx, fy;
bool vis[maxn][maxn][2000];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int ans;

struct Node
{
    int x, y, depth;
    int state; //state用来记录到当前这个点能打开哪几扇门，即捡到了哪几把钥匙
};

inline bool check(int a, int b)
{
    return 0 <= a && a < n && 0 <= b && b < m;
}

void bfs()
{
    queue<Node> que;
    que.push(Node{sx, sy, 0, 0});
    vis[sx][sy][0] = true;
    while (!que.empty())
    {
        Node v = que.front();
        que.pop();
        if (v.x == fx && v.y == fy)
        {
            if (v.depth < t)
                ans = v.depth;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int a = v.x + dir[i][0], b = v.y + dir[i][1];
            if (check(a, b) && mat[a][b] != '*' && v.depth + 1 < t)
            {
                if (mat[a][b] >= 'a' && mat[a][b] <= 'z')
                {
                    int state = v.state | (1 << (mat[a][b] - 'a'));
                    if (!vis[a][b][state])
                    {
                        que.push(Node{a, b, v.depth + 1, state});
                        vis[a][b][state] = true;
                    }
                }
                else if (mat[a][b] >= 'A' && mat[a][b] <= 'Z')
                {
                    int state = v.state & (1 << (mat[a][b] - 'A')); //state不为0，说明能打开当前这扇门
                    if (!vis[a][b][v.state] && state)
                    {
                        vis[a][b][v.state] = true;
                        que.push(Node{a, b, v.depth + 1, v.state});
                    }
                }
                else
                {
                    if (!vis[a][b][v.state])
                    {
                        que.push(Node{a, b, v.depth + 1, v.state});
                        vis[a][b][v.state] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    while (cin >> n >> m >> t)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '@')
                    sx = i, sy = j;
                if (mat[i][j] == '^')
                    fx = i, fy = j;
            }
        bfs();
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}