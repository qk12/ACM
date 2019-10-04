// Luogu 1219
#include <iostream>
using namespace std;

int cur, cnt, n, a[20], vis[3][50]; //全局变量,vis要开大一些，不然会溢出

void queen(int cur)
{
    if (cur == n) //递归边界，只要走到了这里，所有的皇后必然不冲突
    {
        cnt++;
        cout << "No. " << cnt << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++) //既然是逐行放置的，则皇后肯定不会横向攻击，只需检查列向和斜向
        {                           //主对角线标识可能为负，y-x的最小值为-n+1,所以将整体向右偏移n个单位（不影响最终结果）
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
            {                                                          //利用二维数组，检查是否和前面的皇后冲突
                a[cur] = i;                                            //尝试把第cur行的皇后放在第i列
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1; //修改全局变量
                queen(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0; //切记！一定要改回来
            }
        }
    }
}

int main()
{
    cin >> n;
    queen(0);
    return 0;
}