// CodeForces 835B
#include <bits/stdc++.h>
using namespace std;

int a[15];

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        sum += s[i] - '0';
        a[s[i] - '0']++;
    }
    if (sum >= k)
        cout << 0 << endl;
    else
    {
        int ans = 0;
        int id = 0;
        while (sum < k)
        {
            if (a[id])
            {
                ans++;
                sum += 9 - id;
                a[id]--;
            }
            else
                id++;
        }
        cout << ans << endl;
    }
    return 0;
}