// Luogu 3809
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
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

Suffix_Array SA;

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    SA.build_sa(len, 128);
    for (int i = 1; i <= len; ++i)
        printf("%d ", sa[i] + 1);
    return 0;
}