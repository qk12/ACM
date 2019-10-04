// Luogu 1854
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 105;
int a[maxn][maxn], dp[maxn][maxn], ans[maxn][maxn];
int n, m;

int dfs(int i, int j)
{
  if (i == n)
    return a[i][j];
  if (dp[i][j])
    return dp[i][j];
  int res = -INF;
  for (int k = j + 1; k <= m; ++k)
    if (a[i][j] + dfs(i + 1, k) > res)
    {
      res = a[i][j] + dfs(i + 1, k);
      ans[i][j] = k;
    }
  return dp[i][j] = res;
}

void output(int i, int j) //路径查找
{
  if (i >= n)
    return;
  cout << ans[i][j] << ' ';
  output(i + 1, ans[i][j]); //前进
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];

  cout << dfs(0, 0) << endl;
  output(0, 0);
  return 0;
}