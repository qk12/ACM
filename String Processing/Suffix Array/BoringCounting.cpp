// HDU 3518
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1005;
char s[maxn];
int sa[maxn], height[maxn];
struct Suffix_Array //倍增算法构造后缀数组,复杂度O(nlogn)
{
    int t[maxn], t2[maxn], c[maxn], rank[maxn];
    void build_sa(int n, int m) //n为字符串的长度,字符集的值为0~m-1
    {
        n++;
        int *x = t, *y = t2;
        //基数排序
        for (int i = 0; i < m; i++)
            c[i] = 0;
        for (int i = 0; i < n; i++)
            c[x[i] = s[i]]++;
        for (int i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--)
            sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) //直接利用sa数组排序第二关键字
        {
            int p = 0;
            for (int i = n - k; i < n; i++)
                y[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k)
                    y[p++] = sa[i] - k;
            //基数排序第一关键字
            for (int i = 0; i < m; i++)
                c[i] = 0;
            for (int i = 0; i < n; i++)
                c[x[y[i]]]++;
            for (int i = 1; i < m; i++)
                c[i] += c[i - 1];
            for (int i = n - 1; ~i; i--)
                sa[--c[x[y[i]]]] = y[i];
            //根据sa和y数组计算新的x数组
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n)
                break; //以后即使继续倍增，sa也不会改变，推出
            m = p;     //下次基数排序的最大值
        }
        n--;
        int k = 0;
        for (int i = 0; i <= n; i++)
            rank[sa[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (k)
                k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k])
                k++;
            height[rank[i]] = k;
        }
    }
};

int solve(int k, int len)
{
    int maxx = -INF, minn = INF;
    int res = 0;
    for (int i = 1; i <= len; ++i)
    {
        if (height[i] >= k)
        {
            maxx = max(maxx, max(sa[i - 1], sa[i]));
            minn = min(minn, min(sa[i - 1], sa[i]));
        }
        else
        {
            if (maxx - minn >= k)
                ++res;
            maxx = -INF, minn = INF;
        }
    }
    if (maxx - minn >= k)
        ++res;
    return res;
}

Suffix_Array SA;

int main()
{
    while (scanf("%s", s), s[0] != '#')
    {
        int len = strlen(s);
        SA.build_sa(len, 128);
        long long ans = 0;
        for (int i = 1; 2 * i <= len; ++i)
            ans += solve(i, len);
        printf("%lld\n", ans);
    }
    return 0;
}