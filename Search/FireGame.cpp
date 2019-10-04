// FZU 2150
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int maxn = 12;
const int INF = 0x3f3f3f3f;

int N, M;
char maze[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

inline bool check(int a, int b) { return 0 <= a && a < N && 0 <= b && b < M; }
int bfs(PII a, PII b)
{
    int ans = 0;
    vis[a.first][a.second] = 0;
    vis[b.first][b.second] = 0;
    queue<PII> q;
    while (!q.empty())
        q.pop();
    q.push(a);
    q.push(b);
    while (!q.empty())
    {
        PII temp = q.front();
        q.pop();
        int x = temp.first, y = temp.second;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dir[i][0], b = y + dir[i][1];
            if (check(a, b) && vis[a][b] == -1 && maze[a][b] == '#')
            {
                ans = vis[a][b] = vis[x][y] + 1;
                q.push(make_pair(a, b));
            }
        }
    }
    return ans;
}

bool judge()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (maze[i][j] == '#' && vis[i][j] == -1)
                return false;
    return true;
}

int main()
{
    int T;
    int kase = 0;
    cin >> T;
    while (T--)
    {
        int ans = INF;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> maze[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (maze[i][j] == '#')
                    for (int k = 0; k < N; k++)
                        for (int l = 0; l < M; l++)
                            if (maze[k][l] == '#')
                            {
                                memset(vis, -1, sizeof(vis));
                                int temp = bfs(make_pair(i, j), make_pair(k, l));
                                if (judge())
                                    ans = min(ans, temp);
                            }
        if (ans == INF)
            ans = -1;
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}