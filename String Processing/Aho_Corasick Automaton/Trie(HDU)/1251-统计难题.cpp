#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;
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
    void insert(const char *s)
    {
        int u = 0;
        for (int i = 0; s[i]; ++i)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) //如果走不通，新建节点
                ch[u][c] = newnode();
            u = ch[u][c]; //往下走
            ++val[u];
        }
    }
    int query(const char *s)
    {
        int u = 0;
        for (int i = 0; s[i]; ++i)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                return 0;
            u = ch[u][c];
        }
        return val[u];
    }
};

int main()
{
    char str[15];
    Trie T;
    T.init();
    while (gets(str) && str[0] != '\0')
        T.insert(str);
    while (scanf("%s", str) != EOF)
        printf("%d\n", T.query(str));
    return 0;
}