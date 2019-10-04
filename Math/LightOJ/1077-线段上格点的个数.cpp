#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k)
    {
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        ll a = abs(ax - bx), b = abs(ay - by);
        cout << "Case " << k << ": " << gcd(a, b) + 1 << endl;
    }
    return 0;
}