// HYSBZ 1018
#include <bits/stdc++.h>
using namespace std;

const int maxn = 444444;
#define lson o << 1, l, mid
#define rson o << 1 | 1, mid + 1, r
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define MEM(x, v) memset(x, v, sizeof(x))

struct node
{
    int lft, rig;
    bool l, r, u, d, p, q;
} seg[maxn]; //节点

int n;
bool conn[maxn][2];
void pushup(node &x, node l, node r)
{
    x.lft = l.lft;
    x.rig = r.rig;
    x.l = l.l | (l.u & conn[l.rig][0] & r.l & conn[l.rig][1] & l.d);
    x.r = r.r | (r.u & conn[l.rig][0] & l.r & conn[l.rig][1] & r.d);
    x.u = (l.u & conn[l.rig][0] & r.u) | (l.p & conn[l.rig][1] & r.q);
    x.d = (l.d & conn[l.rig][1] & r.d) | (l.q & conn[l.rig][0] & r.p);
    x.p = (l.u & conn[l.rig][0] & r.p) | (l.p & conn[l.rig][1] & r.d);
    x.q = (l.d & conn[l.rig][1] & r.q) | (l.q & conn[l.rig][0] & r.u);
}
void build(int o, int l, int r)
{ //建树
    if (l == r)
    {
        seg[o].lft = seg[o].rig = l; //叶子节点左右边界
        seg[o].u = seg[o].d = 1;     //左右联通
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(seg[o], seg[o << 1], seg[o << 1 | 1]);
}
void modify1(int o, int l, int r, int p, int row, bool val)
{ //同行修改
    int mid = (l + r) >> 1;
    if (mid == p)
    {
        conn[mid][row] = val;
        pushup(seg[o], seg[o << 1], seg[o << 1 | 1]);
        return;
    }
    if (mid >= p)
        modify1(lson, p, row, val);
    else
        modify1(rson, p, row, val);
    pushup(seg[o], seg[o << 1], seg[o << 1 | 1]);
}
void modify2(int o, int l, int r, int p, bool val)
{ //不同行修改，第p列
    if (l == r)
    {
        seg[o].l = seg[o].r = seg[o].p = seg[o].q = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= p)
        modify2(lson, p, val);
    else
        modify2(rson, p, val);
    pushup(seg[o], seg[o << 1], seg[o << 1 | 1]);
}

node query(int o, int l, int r, int ql, int qr)
{ //查询区间[ql,qr]的节点
    if (l >= ql && r <= qr)
        return seg[o];
    int mid = (l + r) >> 1;
    if (mid < ql)
        return query(rson, ql, qr);
    if (mid >= qr)
        return query(lson, ql, qr);
    node ans;
    pushup(ans, query(lson, ql, qr), query(rson, ql, qr));
    return ans;
}

int main()
{
    n = 0;
    char op[10];
    build(1, 1, n);
    while (~scanf("%s", op) && op[0] != 'E')
    {
        int a = 0, b = 0, c = 0, d = 0;
        switch (op[0])
        {
        case 'C': //关路
            if (a == c)
                modify1(1, 1, n, min(b, d), a - 1, 0); //同一行
            else
                modify2(1, 1, n, b, 0); //不同行
            break;
        case 'O': //开路
            if (a == c)
                modify1(1, 1, n, min(b, d), a - 1, 1);
            else
                modify2(1, 1, n, b, 1);
            break;
        case 'A': //询问
            if (b > d)
                swap(a, c), swap(b, d);                                                                 //列编号小的放前面
            node ans1 = query(1, 1, n, b, d), ans2 = query(1, 1, n, 1, b), ans3 = query(1, 1, n, d, n); //三段
            bool flag = false;
            if (a == 1)
            {
                if (c == 1)
                { //左上，右上
                    if (ans1.u)
                        flag = true; //直接走上面
                    if (ans2.r & ans1.d & ans3.l)
                        flag = true; //绕路走
                }
                else
                { //左上，右下
                    if (ans1.p)
                        flag = true; //直接走
                    if (ans2.r & ans1.d)
                        flag = true; //从左边绕
                    if (ans3.l & ans1.u)
                        flag = true; //从右边绕
                }
            }
            else
            {
                if (c == 1)
                { //左下，右上
                    if (ans1.q)
                        flag = true; //直接走
                    if (ans2.r & ans1.u)
                        flag = true; //从左边绕
                    if (ans3.l & ans1.d)
                        flag = true; //从右边绕
                }
                else
                { //左下，右下
                    if (ans1.d)
                        flag = true; //直接走
                    if (ans2.r & ans1.u & ans3.l)
                        flag = true; //绕路走
                }
            }
            puts(flag ? "Y" : "N");
        }
    }
}