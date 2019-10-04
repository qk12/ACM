// Luogu 2758
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
char s1[maxn], s2[maxn];
int dp[maxn][maxn];

//删除一个字符                  dfs(i - 1, j) + 1
//插入一个字符(理解为将B[j]删掉)  dfs(i, j - 1) + 1
//将一个字符改为另一个字符        dfs(i - 1, j - 1) + 1
int dfs(int i, int j)
{
    if (i == 0)
        return dp[i][j] = j;
    if (j == 0)
        return dp[i][j] = i;
    if (dp[i][j] > 0)
        return dp[i][j];
    int bonus = 1;
    if (s1[i] == s2[j]) //相等
        bonus = 0;
    return dp[i][j] = min(min(dfs(i - 1, j) + 1, dfs(i, j - 1) + 1), dfs(i - 1, j - 1) + bonus);
}

int main()
{
    cin >> (s1 + 1) >> (s2 + 1);
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    cout << dfs(len1, len2) << endl;
    return 0;
}