// Luogu 1896
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10;
ll dp[maxn][1 << maxn][maxn * maxn]; //dp[i][j][k]表示第i行，状态为S[j]，前面摆了k个国王时，方案数
int S[1 << maxn], king[1 << maxn];   //S[]是当前状态，king[state]是state状态的国王数
long long cnt;                       //cnt是用来记录状态总数的，sum是用来计算一共有多少种方案的
int n, K;
ll ans;

inline bool check(int j, int p)
{
    return !(S[j] & S[p]) &&
           !(S[j] & (S[p] << 1)) &&
           !((S[j] << 1) & S[p]);
}

int dfs(int i, int state, int k)
{
    if (k == K)
    {
        return ++dp[i][state][k];
    }

    if (dp[i][state][k] > 0)
        return dp[i][state][k];

    ll res = 0;
    for (int j = 1; j <= cnt; ++j)
        if (check(state, j) && i + 1 <= n && k + king[j] <= K)
            res += dfs(i + 1, j, k + king[j]);

    return dp[i][state][k] = res;
}

void init()
{
    int tot = (1 << n) - 1; //最多到这个时候，就是二进制下，每一位上都放上国王，当然有不行的，为了方便下文排除
    for (int i = 0; i <= tot; i++)
        if (!((i << 1) & i)) //因为要互不侵犯，所以，两个国王之间必须隔一个，这是判断是否满足题意国王之间不相互攻击
        {
            S[++cnt] = i; //找到了满足的，记录这个状态
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
    cin >> n >> K;
    init();
    memset(dp, 0, sizeof(dp));

    int sum = 0;
    for (int j = 1; j <= cnt; ++j) //先处理第一行
        if (king[j] <= K)          //一行的国王数一定不能超过总数
        {
            dp[1][j][king[j]] = 1;
            sum += dfs(1, j, king[j]);
        }

    /*
    for (int j = 1; j <= cnt; j++)
        sum += dfs(1, j, king[j]) + dp[1][j][king[j]];
    */
    for (int i = 1; i <= n; i++) //因为不确定在哪一行用光国王，所以都枚举一遍；
        for (int j = 1; j <= cnt; j++)
            sum += dp[i][j][K]; //本行及以前用光了国王，那么方案数加在总数中；
    cout << sum << endl;
    return 0;
}