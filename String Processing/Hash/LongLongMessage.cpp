// poj 2774
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const ull B = 100000007; //哈希的基数
//const int mod = 1e9 + 7;
int n, m;
char x[maxn], y[maxn];

vector<ull> Hash;
bool check(int len)
{
    Hash.clear();
    ull t = 1;
    for (int i = 0; i < len; ++i) //计算B的n次方
        t = t * B;
    ull ah = 0, bh = 0;
    for (int i = 0; i < len; ++i) //计算a和b长度为n的前缀对应的哈希值
    {
        ah = (ah * B + x[i]);
        bh = (bh * B + y[i]);
    }
    Hash.push_back(ah);
    for (int i = 0; i + len < n; i++) //对b不断右移一位，更新哈希值并判断
    {
        ah = (ah * B - x[i] * t + x[i + len]);
        Hash.push_back(ah);
    }
    sort(Hash.begin(), Hash.end());

    if (binary_search(Hash.begin(), Hash.end(), bh))
        return true;
    for (int i = 0; i + len < m; i++) //对b不断右移一位，更新哈希值并判断
    {
        bh = (bh * B - y[i] * t + y[i + len]);
        if (binary_search(Hash.begin(), Hash.end(), bh))
            return true;
    }
    return false;
}

int main()
{
    while (scanf("%s%s", x, y) != EOF)
    {
        n = strlen(x), m = strlen(y);
        int len = min(n, m);
        int L = 0, R = len; //初始化解的存在范围
        int ans = 0;
        while (L <= R)
        {
            int mid = L + (R - L) / 2;
            if (check(mid))
            {
                ans = mid;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}