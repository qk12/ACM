// HDU 2243
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ull> vec;
typedef vector<vec> mat;
mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] += A[i][k] * B[k][j];
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++)
        B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1)
            B = mul(B, A);
    return B;
}

const int maxn = 35;
struct Trie
{
    int ch[maxn][26], f[maxn];
    bool val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char *s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                {
                    f[ch[u][c]] = ch[f[u]][c];
                    q.push(ch[u][c]);
                }
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    ull query(ll n)
    {
        mat A(sz + 1, vec(sz + 1));
        mat B(2, vec(2));
        B[0][0] = 26, B[0][1] = B[1][1] = 1;
        for (int i = 0; i < sz; i++)
            if (!val[i])
                for (int j = 0; j < 26; j++)
                    if (!val[ch[i][j]])
                        A[i][ch[i][j]]++;
        for (int i = 0; i < sz + 1; i++)
            A[i][sz] = 1;
        A = Pow(A, n);
        B = Pow(B, n);
        ull tot = 0;
        for (int i = 0; i < sz + 1; i++)
            tot += A[0][i];
        ull ans = B[0][0] + B[0][1];
        ans -= tot;
        return ans;
    }
};

Trie ac;

int main()
{
    int m;
    ll n;
    char s[10];
    while (~scanf("%d%lld", &m, &n))
    {
        ac.init();
        while (m--)
        {
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        printf("%llu\n", ac.query(n));
    }
    return 0;
}
