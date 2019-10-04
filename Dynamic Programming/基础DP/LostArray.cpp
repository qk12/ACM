// CodeForces 1105C
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
ll dp[maxn][3]; //dp[i][0~2]表示到第i位置时余数为0、1、2的方案数

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    //预处理出[L,R]范围内模3余0、1、2的数有多少个
    int r0, r1, r2;
    r0 = r / 3 - (l - 1) / 3;             //模3余0
    r1 = (r + 2) / 3 - ((l - 1) + 2) / 3; //模3余1
    r2 = (r + 1) / 3 - ((l - 1) + 1) / 3; //模3余2

    dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    { //第i个位置余0可由第i-1个位置余0再放一个整除3的数、第i - 1个位置余1再放一个除以3余2的数、第i - 1个位置余2再放一个除以3余1的数
        dp[i][0] = (dp[i - 1][0] * r0 + dp[i - 1][1] * r2 + dp[i - 1][2] * r1) % mod;
        dp[i][1] = (dp[i - 1][0] * r1 + dp[i - 1][1] * r0 + dp[i - 1][2] * r2) % mod;
        dp[i][2] = (dp[i - 1][0] * r2 + dp[i - 1][1] * r1 + dp[i - 1][2] * r0) % mod;
    }

    cout << dp[n][0] % mod << endl;
    return 0;
}