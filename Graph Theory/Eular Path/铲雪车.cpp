// ybt 1374
//思路：对于每一条边都有两个方向可走，即每一个单独的点都至少有偶数条边相连，也就是有0个奇点，可从
//任意一点出发并不重复地遍历每一条路，这个图是欧拉图。统计每一条路的长度除速度20千米每小时即答案
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long start, endd;
    cin >> start >> endd;
    long long x1, y1, x2, y2;
    double dis = 0;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        dis += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
    long long ans = dis * 2 / 1000 / 20 * 60 + 0.5; //类型转换：(类型名) 变量或(类型名) (表达式)
    printf("%lld:%02lld", ans / 60, ans % 60);      //特别注意时间格式的输出
    return 0;
}