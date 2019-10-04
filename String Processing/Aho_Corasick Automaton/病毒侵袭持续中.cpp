// HDU 3065
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int ch[maxn][128], f[maxn], val[maxn];
int cnt[1005];
int n;
char s1[10005][55];
char s2[2000005];
struct Trie
{
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    int idx(char c) { return c; };
    void insert(const char *s, int id)
    {
        int u = 0;
        for (int i = 0; s[i]; ++i)
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
        for (int c = 0; c < 128; c++)
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
            for (int c = 0; c < 128; ++c)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int query(const char *s)
    {
        int u = rt;
        int res = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; s[i]; ++i)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            int temp = u;
            while (temp != rt)
            {
                if (val[temp])
                    ++cnt[val[temp]];
                temp = f[temp];
            }
        }
        for (int i = 1; i <= n; ++i)
            if (cnt[i])
                printf("%s: %d\n", s1[i], cnt[i]);
        return res;
    }
};

int main()
{
    Trie T;
    while (scanf("%d", &n) != EOF)
    {
        T.init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", s1[i]);
            T.insert(s1[i], i);
        }
        T.build();
        scanf("%s", s2);
        T.query(s2);
    }
    return 0;
}
