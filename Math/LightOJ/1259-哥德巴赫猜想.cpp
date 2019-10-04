#include <iostream>
using namespace std;

const int maxn = 1e7;
int prime[664588];       //存素数
bool is_prime[maxn + 1]; //判定素数

int getPrime(int n) //返回n以内素数的个数
{
    int cnt = 0;
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    int temp = getPrime(1e7);
    int n;
    int kase = 0;
    while (T--)
    {
        cin >> n;
        cout << "Case " << ++kase << ": ";
        int cnt = 0;
        for (int i = 0; i < temp && 2 * prime[i] <= n; ++i)
        {
            if (is_prime[n - prime[i]])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}