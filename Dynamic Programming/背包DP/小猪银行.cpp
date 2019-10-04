#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 505;
const int maxm = 10005;
int n, m;                       //物品种数、容量
int w[maxn], v[maxn], dp[maxm]; //weight、value

void CompletePack(int weight, int value) //完全背包（n种物品，背包容量为m，每种物品都有无限件可用）
{
    for (int j = weight; j <= m; ++j) //递增，保证当前层答案是由上一层右半部分递推而来（右半部分选了多件）
        dp[j] = min(dp[j], dp[j - weight] + value);
}

int main()
{
    int T;
    cin >> T;
    int e, f;
    while (T--)
    {
        for (int i = 1; i < maxm; ++i)
            dp[i] = INF;
        dp[0] = 0;
        cin >> e >> f;
        m = f - e;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i] >> w[i];
        for (int i = 0; i < n; ++i)
            CompletePack(w[i], v[i]);
        if (dp[m] == INF)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[m] << "." << endl;
    }
    return 0;
}