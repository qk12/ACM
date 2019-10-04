#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
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
    int query()
    {
        int res = 0;
        for (int i = 1; i <= sz; ++i)
            if (val[i])
                ++res;
        return res;
    }
};

string str, s;
int main()
{
    Trie T;
    while (getline(cin, str) && str[0] != '#')
    {
        T.init();
        stringstream ss(str);
        while (ss >> s)
            T.insert(s);
        printf("%d\n", T.query());
    }
    return 0;
}