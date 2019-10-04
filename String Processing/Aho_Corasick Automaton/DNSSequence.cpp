// poj 2778
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int mod = 100000;

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
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

const int maxn = 105;
struct Trie
{
    int ch[maxn][26], f[maxn];
    bool val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c)
    {
        switch (c)
        {
        case 'A':
            return 0;
        case 'G':
            return 1;
        case 'C':
            return 2;
        case 'T':
            return 3;
        }
        return -1;
    };
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
        for (int c = 0; c < 4; c++)
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
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    ll query(int n)
    {
        mat A(sz, vec(sz));
        for (int i = 0; i < sz; i++)
            if (!val[i])
                for (int j = 0; j < 4; j++)
                    if (!val[ch[i][j]])
                        ++A[i][ch[i][j]];
        A = Pow(A, n);
        ll ans = 0;
        for (int i = 0; i < sz; i++)
            ans = (ans + A[0][i]) % mod;
        return ans;
    }
};

Trie ac;

int main()
{
    int m;
    ll n;
    char s[15];
    while (~scanf("%d%lld", &m, &n))
    {
        ac.init();
        while (m--)
        {
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        printf("%lld\n", ac.query(n));
    }
    return 0;
}