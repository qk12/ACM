// Luogu 1433
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
bool vis[maxn];
double x[maxn], y[maxn];
double dis[maxn][maxn];
double ans = 1000000000; //保证ans比每条路径都要长
int n;

void dfs(int depth, int now, double length) //depth 已经走过几个点 now 当前走到的点,length 走到的当前路径长
{
    if (length > ans) //剪枝（不然会超时） 当前路径已经比当前最短的要长了，就不必继续搜索，
        return;       //直接返回上一层
    if (depth == n)   //走完n个点
    {
        ans = min(ans, length); //更新最短路径值
        return;
    }
    for (int i = 1; i <= n; i++) //枚举所有点
        if (!vis[i])             //没有走过
        {
            vis[i] = true;                           //标记为走过
            dfs(depth + 1, i, length + dis[now][i]); //深搜下一层
            vis[i] = false;                          //回溯  从刚才上一层退回，把标记过的点取消标记
        }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    x[0] = 0, y[0] = 0;          //设起点为第0个点
    for (int i = 0; i <= n; i++) //预处理两点间距离
        for (int j = 0; j <= n; j++)
            dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

    dfs(0, 0, 0.0); //已走过0个点  上一个点是第0个点  已走了长0.0的路径

    printf("%.2f\n", ans);
    return 0;
}