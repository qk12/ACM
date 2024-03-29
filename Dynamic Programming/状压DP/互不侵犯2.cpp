// Luogu 1896
#include <bits/stdc++.h>
using namespace std;

long long dp[10][15000][80];          //dp[i][j][k]表示第i行，状态为j，前面摆了k个国王时，方案数
long long state[777777], king[77777]; //state[]是当前状态，king[]是当前行的国王数
long long cnt, sum;                   //cnt是用来记录状态总数的，sum是用来计算一共有多少种方案的
int n, k;

void init()
{
    int tot = (1 << n) - 1; //最多到这个时候，就是二进制下，每一位上都放上国王，当然有不行的，为了方便下文排除
    for (int i = 0; i <= tot; i++)
        if (!((i << 1) & i)) //因为要互不侵犯，所以，两个国王之间必须隔一个，这是判断是否满足题意国王之间不相互攻击
        {
            state[++cnt] = i; //找到了满足的，记录这个状态
            int temp = i;
            while (temp) //判断这个状态有多少个国王，也就是t在二进制下有多少个1
            {
                king[cnt] += temp % 2;
                temp >>= 1; //记住，是右移一位，和  t/=2 一样，就是稍微快一点
            }
        }
}

int main()
{
    cin >> n >> k;
    init();

    for (int i = 1; i <= cnt; i++) //先处理第一行
        if (king[i] <= k)          //一行的国王数一定不能超过总数
            dp[1][i][king[i]] = 1;

    for (int i = 2; i <= n; i++)           //处理剩下的，所以从 2 开始枚举
        for (int j = 1; j <= cnt; j++)     //枚举状态
            for (int p = 1; p <= cnt; p++) //再一遍状态，用来当作上一行的状态，因为 我们由上向下递推，能迎上本行的，只有上一行
            {                              //这里就不在赘述了，和处理第一行同理，但是不同的是这里处理相邻的行
                if (state[j] & state[p])   //上下相邻不行
                    continue;
                if (state[j] & (state[p] << 1)) //本行的右上角不能有国王
                    continue;
                if ((state[j] << 1) & state[p]) //左上角也不行
                    continue;
                for (int s = 1; s <= k; s++) //s表示本行以上用了多少国王
                {                            //满足条件后，还要记得国王数量是有限的！！
                    if (king[j] + s > k)     //我们是递推，所以本行以上一定处理完了，所以，本行加以前用过的国王，总数不能超过限定
                        continue;
                    dp[i][j][king[j] + s] += dp[i - 1][p][s]; //还记得dp[i][j][k]中的k表示已经用过的国王数，而king[]是本行的，s是本行以前的
                }
            }

    for (int i = 1; i <= n; i++) //因为不确定在哪一行用光国王，所以都枚举一遍；
        for (int j = 1; j <= cnt; j++)
            sum += dp[i][j][k]; //本行及以前用光了国王，那么方案数加在总数中；

    cout << sum << endl;
    return 0;
}