// HDU 2222
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int ch[maxn][26], f[maxn], val[maxn];
struct Trie
{
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char *s)
    {
        int u = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                ch[u][c] = newnode();
            u = ch[u][c];
        }
        ++val[u];
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
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
            for (int c = 0; c < 26; ++c)
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
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            int tmp = u;
            while (tmp != rt)
            {
                res += val[tmp];
                val[tmp] = 0;
                tmp = f[tmp];
            }
        }
        return res;
    }
} ac;

char s[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        ac.init();
        while (n--)
        {
            cin >> s;
            ac.insert(s);
        }
        ac.build();
        cin >> s;
        cout << ac.query(s) << endl;
    }
    return 0;
}
