// Luogu 1120
#include <bits/stdc++.h>
using namespace std;

const int maxn = 70;
int n, m, cnt, sum, len;
int a[maxn], nxt[maxn];
bool vis[maxn];
bool flag;

//k为正在拼的木棍的编号，last为正在拼的木棍的前一节编号，rest为该木棍还未拼的长度
void dfs(int k, int last, int rest)
{
    if (rest == 0)
    { //未拼的长度为0，说明这根原始长棍拼完了，准备拼下一个
        if (k == m)
        {
            flag = true;
            return;
        } //优化6，全部拼完并符合要求，找到答案，直接返回

        int i;
        for (i = 1; i <= cnt; i++) //找一个还没用的最长的木棍打头即可。反正要想全都拼接成功，每根木棍都得用上
            if (!vis[i])
                break;
        vis[i] = true;
        dfs(k + 1, i, len - a[i]);
        vis[i] = false;
        if (flag)
            return; //优化6，找到答案就退出
    }
    //优化4，二分找第一个木棍长度不大于未拼长度rest 的位置
    int L = last + 1, R = cnt;
    while (L < R)
    {
        int mid = L + (R - L) / 2;
        if (a[mid] <= rest)
            R = mid;
        else
            L = mid + 1;
    }
    for (int i = L; i <= cnt; i++)
    {
        if (!vis[i]) //优化5，判断木棍是否用过
        {
            vis[i] = true;
            dfs(k, i, rest - a[i]);
            vis[i] = false;
            if (flag)
                return; //优化6，找到答案就退出

            if (rest == a[i] || rest == len)
                return; //优化7
            i = nxt[i]; //优化3
            if (i == cnt)
                return;
        }
    }
    //到了这里，说明这时候拼不成当前这根原始木棍了，传回失败信息并修改之前拼的木棍
}

int main()
{
    while (scanf("%d", &n), n)
    {
        memset(a, 0, sizeof(a));
        memset(nxt, 0, sizeof(nxt));
        memset(vis, 0, sizeof(vis));
        cnt = 0, sum = 0, len = 0;
        flag = false;

        int d;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d);
            if (d > 50)
                continue;
            a[++cnt] = d;
            sum += d;
        }

        sort(a + 1, a + 1 + cnt, greater<int>()); //优化1，木棍按长度从大到小排序

        //优化3，预处理nxt数组
        nxt[cnt] = cnt;
        for (int i = cnt - 1; i > 0; i--)
        {
            if (a[i] == a[i + 1])
                nxt[i] = nxt[i + 1];
            else
                nxt[i] = i;
        }

        int ans = 0;
        for (len = a[1]; len <= sum / 2; len++)
        { //枚举原始长度
            if (sum % len != 0)
                continue;  //如果不能拼出整数根 就跳过
            m = sum / len; //优化6中的那个计算
            flag = false;
            vis[1] = true;
            dfs(1, 1, len - a[1]);
            vis[1] = false;
            if (flag)
            {
                ans = len;
                break;
            } //优化6，输出答案，退
        }
        printf("%d\n", ans == 0 ? sum : len);
    }
    return 0;
}