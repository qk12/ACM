#include <bits/stdc++.h>
using namespace std;

bool flag = true;

const int maxn = 100005;
int ch[maxn][12], val[maxn]; //val[u]为节点u存储的信息
struct Trie
{
    int sz, rt;                    //已有节点数、树根
    int newnode() { return sz++; } //新建节点
    void init()                    //初始化，建立根节点
    {
        sz = 0, rt = newnode();
        memset(ch, -1, sizeof(ch)), memset(val, 0, sizeof(val));
    }
    int idx(char c) { return c - '0'; }; //ASCII码减成数字
    void insert(const char *s)
    {
        int u = 0;
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) //如果走不通，新建节点
                ch[u][c] = newnode();
            else if (i == len - 1)
                flag = false;
            u = ch[u][c]; //往下走
            if (val[u])
                flag = false;
        }
        val[u] = 1;
    }
};

char a[15];
int main()
{
    int t;
    scanf("%d", &t);
    int n;
    Trie T;
    while (t--)
    {
        T.init();
        flag = true;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s", a);
            if (flag)
                T.insert(a);
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
