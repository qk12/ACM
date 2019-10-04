// UVA 11426
#include <iostream>
using namespace std;

const int maxn = 4e6 + 5;
int euler[maxn];
void euler_phi2(int n) //筛出欧拉函数值的表
{
    for (int i = 0; i <= n; ++i)
        euler[i] = i;
    for (int i = 2; i <= n; ++i)
        if (euler[i] == i)
            for (int j = i; j <= n; j += i)
                euler[j] = euler[j] / i * (i - 1);
}

long long s[maxn], f[maxn];
int main()
{
    euler_phi2(maxn);
    for (int i = 1; i <= maxn; ++i)
        for (int j = i + i; j <= maxn; j += i) //最大公约数不能为本身
            f[j] += i * euler[j / i];
    for (int i = 1; i <= maxn; ++i)
        s[i] = s[i - 1] + f[i];
    int n;
    while (cin >> n, n)
        cout << s[n] << endl;
    return 0;
}