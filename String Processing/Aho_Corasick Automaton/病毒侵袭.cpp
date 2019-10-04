// HDU 2896
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int ch[maxn][100], f[maxn], val[maxn];
bool vis[505];
int n;
struct Trie
{
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    int idx(char c) { return c - ' '; };
    void insert(const char *s, int id)
    {
        int u = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = id;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 100; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 100; ++c)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int query(const char *s, int id)
    {
        int u = rt;
        memset(vis, 0, sizeof(vis));
        bool flag = false;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            int temp = u;
            while (temp != rt)
            {
                if (val[temp])
                {
                    vis[val[temp]] = true;
                    flag = true;
                }
                temp = f[temp];
            }
        }
        if (!flag)
            return 0;
        printf("web %d:", id);
        for (int i = 1; i <= n; i++)
            if (vis[i])
                printf(" %d", i);
        printf("\n");
        return 1;
    }
};

char s[10005];
int main()
{
    scanf("%d", &n);
    Trie T;
    T.init();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        T.insert(s, i);
    }
    T.build();
    int m;
    scanf("%d", &m);
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", s);
        if (T.query(s, i))
            ++res;
    }
    printf("total: %d\n", res);
    return 0;
}
