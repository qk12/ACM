// Luogu 1508
#include <iostream>
using namespace std;

const int maxn = 205;
int a[maxn][maxn], dp[maxn][maxn];
int n, m;

int main()
{
    cin >> n >> m;
    int x = n;
    int y = m / 2 + 1; //求出李大水牛最开始的位置
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            a[i][j] = -99999; //设置边界，为了避免李大水牛吃到餐桌外面去。。
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j]; //输入

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + a[i][j]; //动态方程
        }
    }
    cout << max(max(dp[x][y], dp[x][y - 1]), dp[x][y + 1]) << endl; //因为最大值只可能在李大水牛的前方、左前方、右前方，所以只要找这三个的最大就行了
    return 0;
}