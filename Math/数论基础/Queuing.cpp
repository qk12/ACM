// HDU 2604
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec; //要用long long，不然会爆
typedef vector<vec> mat;
int mod;

mat mul(mat &A, mat &B) //计算A*B
{
    mat C(A.size(), vec(B[0].size())); //A矩阵的列数、B矩阵的行数
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            if (A[i][k]) //对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); ++j)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod; //中间也要取模，不然会爆
    return C;
}

mat matpow(mat A, ll k) //计算A^k
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i) //单位矩阵
        B[i][i] = 1;
    for (; k; k >>= 1, A = mul(A, A))
        if (k & 1)
            B = mul(B, A);
    return B;
}

mat A(4, vec(4));

void init()
{
    A[0][0] = 1, A[0][1] = 0, A[0][2] = 1, A[0][3] = 1;
    A[1][0] = 1, A[1][1] = 0, A[1][2] = 0, A[1][3] = 0;
    A[2][0] = 0, A[2][1] = 1, A[2][2] = 0, A[2][3] = 0;
    A[3][0] = 0, A[3][1] = 0, A[3][2] = 1, A[3][3] = 0;
}

int main()
{
    init();
    int n;
    while (cin >> n >> mod)
    {
        mat C = matpow(A, n); //矩阵快速幂
        cout << (6 * C[3][0] + 4 * C[3][1] + 2 * C[3][2] + C[3][3]) % mod << endl;
    }
    return 0;
}