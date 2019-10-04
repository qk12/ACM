// HDU 1069
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
struct node
{
    int a, b, c;
    bool operator<(const node &rhs) const
    {
        return a * b < rhs.a * rhs.b;
    }
    node(int _a, int _b, int _c)
    {
        if (_a > _b)
            swap(_a, _b);
        a = _a, b = _b, c = _c;
    }
};

vector<node> v;
int dp[maxn];

int main()
{
    int n;
    int kase = 0;
    while (cin >> n, n)
    {
        v.clear();
        while (n--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back(node(a, b, c));
            v.push_back(node(b, c, a));
            v.push_back(node(c, a, b));
        }
        sort(v.begin(), v.end());
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            int tmp = 0;
            for (int j = 0; j < i; ++j)
                if ((v[i].a > v[j].a) && (v[i].b > v[j].b))
                    tmp = max(tmp, dp[j]);
            dp[i] = tmp + v[i].c;
            ans = max(ans, dp[i]);
        }
        cout << "Case " << ++kase << ": maximum height = " << ans << endl;
    }
    return 0;
}
