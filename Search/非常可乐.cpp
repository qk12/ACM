// HDU 1495
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y, z, depth;
};

int n, m, s;
bool vis[105][105][105];

bool check(int a, int b, int c)
{
    if (a == b && c == 0)
        return true;
    if (a == c && b == 0)
        return true;
    if (b == c && a == 0)
        return true;
    return false;
}

int bfs()
{
    queue<Node> q;
    q.push(Node{0, 0, s, 0});
    vis[0][0][s] = true;
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        int a = temp.x, b = temp.y, c = temp.z;
        if (check(a, b, c))
            return temp.depth;
        int t1[] = {min(a + c, n), a, max(a + b - m, 0), 0, min(a + b, n), a};
        int t2[] = {b, min(b + c, m), min(a + b, m), b, max(a + b - n, 0), 0};
        int t3[] = {max(a + c - n, 0), max(b + c - m, 0), c, a + c, c, b + c};
        for (int i = 0; i < 6; ++i)
        {
            if (!vis[t1[i]][t2[i]][t3[i]])
            {
                q.push(Node{t1[i], t2[i], t3[i], temp.depth + 1});
                vis[t1[i]][t2[i]][t3[i]] = true;
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> s >> n >> m)
    {
        if (n == 0 || m == 0 || s == 0)
            break;
        if (s % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        memset(vis, 0, sizeof(vis));
        int ans = bfs();
        if (ans == -1)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}