// Luogu 4551
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5; //一般>=1e5
int ch[maxn][2];          //val[u]为节点u存储的信息
struct Trie
{
    int sz, rt;                    //已有节点数、树根
    int newnode() { return sz++; } //新建节点
    void init()                    //初始化，建立根节点
    {
        sz = 0, rt = newnode();
        memset(ch, -1, sizeof(ch));
    }
    int idx(char c) { return c - '0'; }; //ASCII码减成数字
    void insert(int x)                   //const string &s
    {
        int u = 0;
        for (int i = 30; i >= 0; --i) //i<s.length()
        {
            int c = (x >> i) & 1;
            if (ch[u][c] == -1) //如果走不通，新建节点
                ch[u][c] = newnode();
            u = ch[u][c]; //往下走
        }
    }
    int query(int x)
    {
        int u = 0, res = 0;
        for (int i = 30; i >= 0; --i)
        {
            int c = (x >> i) & 1;
            if (ch[u][c ^ 1] == -1)
                u = ch[u][c];
            else
                u = ch[u][c ^ 1], res += (1 << i);
        }
        return res;
    }
};

int dis[maxn];
vector<int> G[maxn];
vector<int> l[maxn];
void dfs(int u, int father)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (v != father)
        {
            dis[v] = (dis[u] ^ l[u][i]);
            dfs(v, u);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Trie T;
    T.init();
    int u, v, w;
    for (int i = 1; i <= n - 1; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(v);
        G[v].push_back(u);
        l[u].push_back(w);
        l[v].push_back(w);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        T.insert(dis[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, T.query(dis[i]));
    printf("%d\n", ans);
    return 0;
}