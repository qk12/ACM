#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int ch[maxn][26], val[maxn]; //val[u]为节点u存储的信息
struct Trie
{
    int sz, rt;                    //已有节点数、树根
    int newnode() { return sz++; } //新建节点
    void init()                    //初始化，建立根节点
    {
        sz = 0, rt = newnode();
        memset(ch, -1, sizeof(ch)), memset(val, 0, sizeof(val));
    }
    int idx(char c) { return c - 'a'; }; //ASCII码减成数字
    void insert(const string &s)
    {
        int u = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) //如果走不通，新建节点
                ch[u][c] = newnode();
            u = ch[u][c]; //往下走
        }
        val[u] = 1; //走到底后的操作
    }
    int query(const string &s) //查询
    {
        int u = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                return 0;
            u = ch[u][c];
        }
        return val[u];
    }
};

string str[50005];
string x, y;
int main()
{
    int cnt = 0;
    Trie T;
    T.init();
    while (cin >> str[cnt])
    {
        T.insert(str[cnt]);
        ++cnt;
    }
    for (int i = 0; i < cnt; ++i)
        for (int k = 1; k < str[i].length() - 1; ++k)
        {
            x = str[i].substr(0, k);
            y = str[i].substr(k, str[i].size() - 1);
            if (T.query(x) && T.query(y))
            {
                cout << str[i] << endl;
                break;
            }
        }
    return 0;
}