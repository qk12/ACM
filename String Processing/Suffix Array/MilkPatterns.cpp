// POJ 3261
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2e4 + 5;
int s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rnk[maxn], height[maxn];
void build_sa(int m, int n)
{
    n++;
    int *x = t, *y = t2;
    for (int i = 0; i < m; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++)
        c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--)
        sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n - k; i < n; i++)
            y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k)
                y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++)
            c[i] = 0;
        for (int i = 0; i < n; i++)
            c[x[y[i]]]++;
        for (int i = 0; i < m; i++)
            c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--)
            sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        rnk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k)
            k--;
        int j = sa[rnk[i] - 1];
        while (s[i + k] == s[j + k])
            k++;
        height[rnk[i]] = k;
    }
}

bool check(int mid, int n, int k)
{
    int cnt = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (height[i] >= mid)
            ++cnt;
        else
            cnt = 1;
        if (cnt >= k)
            return true;
    }
    return false;
}

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &s[i]);
            m = max(m, s[i] + 1);
        }
        build_sa(m, n);
        int L = 1, R = n + 1;
        while (L < R)
        {
            int mid = L + (R - L) / 2;
            if (check(mid, n, k))
                L = mid + 1;
            else
                R = mid;
        }
        printf("%d\n", L - 1);
    }
    return 0;
}
