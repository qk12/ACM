// HDU 2612
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int maxn = 205;
char maze[maxn][maxn];
int N, M;
const int INF = 0x3f3f3f3f;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

inline bool check(int a, int b) { return 0 <= a && a < N && 0 <= b && b < M; }
void bfs(int init_x, int init_y, int vis[][maxn])
{
    queue<P> q;
    vis[init_x][init_y] = 0;
    q.push(P{init_x, init_y});
    while (!q.empty())
    {
        P temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = temp.first + dir[i][0], b = temp.second + dir[i][1];

            if (check(a, b) && !vis[a][b] && maze[a][b] != '#')
            {
                vis[a][b] = vis[temp.first][temp.second] + 1;
                q.push(P{a, b});
            }
        }
    }
}

int visy[maxn][maxn];
int vism[maxn][maxn];
int y_x, y_y, m_x, m_y;

int main()
{
    while (cin >> N >> M)
    {
        memset(visy, 0, sizeof(visy));
        memset(vism, 0, sizeof(vism));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'Y')
                    y_x = i, y_y = j;
                else if (maze[i][j] == 'M')
                    m_x = i, m_y = j;
            }
        bfs(m_x, m_y, vism);
        bfs(y_x, y_y, visy);
        int ans = INF;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == '@' && visy[i][j] && vism[i][j])
                    ans = min(ans, visy[i][j] + vism[i][j]);
            }
        cout << (ans * 11) << endl;
    }
    return 0;
}