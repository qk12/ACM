// SPOJ
//给一个字符串 S ，计算不同子串的个数
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 250005;
struct SAM
{ //每个状态v对应一个或多个字符串，记longest(v)是其中最长者，len(v)是其长度
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last; //sz为当前后缀自动机节点的总数
    //last为未加入此字符前最长的前缀（整个串）所属的节点的编号
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void reset() { last = 0; }
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p = last;
        while (p != -1 && ch[p][c] == -1)
            ch[p][c] = np, p = link[p];
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                while (p != -1 && ch[p][c] == q)
                    ch[p][c] = nq, p = link[p];
            }
        }
        last = np;
    }
} sam;

char s[maxn], t[maxn];

int main()
{
    while (~scanf("%s%s", s, t))
    {
        sam.init();
        int n = strlen(s), m = strlen(t);
        for (int i = 0; i < n; ++i)
            sam.extend(s[i] - 'a');
        int v = 0, len = 0, ans = 0;
        for (int i = 0; i < m; ++i)
        {
            while (v && sam.ch[v][t[i] - 'a'] == -1)
                v = sam.link[v], len = sam.len[v];
            if (sam.ch[v][t[i] - 'a'] != -1)
                v = sam.ch[v][t[i] - 'a'], ++len;
            ans = max(ans, len);
        }
        printf("%d\n", ans);
    }
    return 0;
}