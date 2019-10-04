// UVA 11827
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, num[100];
string s;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
    int T;
    cin >> T;
    getchar(); //getline会读到换行符
    while (T--)
    {
        getline(cin, s);    //把整行读入
        stringstream ss(s); //把数取出来
        n = 0;
        while (ss >> num[n]) // 把数取出来
            ++n;
        ll res = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                res = max(res, gcd(num[i], num[j]));
        cout << res << endl;
    }
    return 0;
}