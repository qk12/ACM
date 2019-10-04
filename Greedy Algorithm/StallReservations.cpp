// POJ 3190
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
    int bg, ed, num;
    bool operator<(const Node &rhs) const
    {
        return ed > rhs.ed;
    }
} x[50005];

bool cmp(const Node &a, const Node &b)
{
    if (a.bg == b.bg)
        return a.ed < b.ed; //最早结束的
    return a.bg < b.bg;
}

int num[50005];

int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<Node> q;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x[i].bg, &x[i].ed);
        x[i].num = i; //牛编上号
    }
    sort(x, x + n, cmp); //排序
    int cnt = 0;
    num[x[0].num] = cnt++; //第一头牛的编号
    q.push(x[0]);
    for (int i = 1; i < n; ++i)
    {
        Node st = q.top();
        if (x[i].bg > st.ed) //有头牛的时间结束
        {
            q.pop();
            num[x[i].num] = num[st.num]; //下头牛 使用这个编号
        }
        else //当前没有结束
        {
            num[x[i].num] = cnt++;
        }
        q.push(x[i]);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", num[i] + 1);
    }
    return 0;
}