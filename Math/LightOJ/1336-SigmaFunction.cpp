#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >> T;
    ll n;
    for (int i = 1; i <= T; ++i)
    {
        cin >> n;
        ll ans = n;
        ans -= (ll)sqrt(n) + (ll)sqrt(n / 2.0);
        printf("Case %d: %lld\n", i, ans);
    }
    return 0;
}