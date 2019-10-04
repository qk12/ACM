// POJ 3278
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100005;
bool vis[maxn];

struct Node
{
    int depth, state;
};

int bfs(int n, int k)
{
    queue<Node> q;
    Node s{0, n};
    q.push(s);
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if (temp.state == k)
            return temp.depth;
        if (temp.state < 0 || temp.state > maxn || vis[temp.state])
            continue;
        s.depth = temp.depth + 1;
        s.state = temp.state * 2;
        q.push(s);
        s.state = temp.state + 1;
        q.push(s);
        s.state = temp.state - 1;
        q.push(s);
        vis[temp.state] = true;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}