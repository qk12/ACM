// HDU 4847
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cnt = 0;
    while (cin >> s)
    {
        int len = s.length();
        for (int i = 0; i < len - 3; ++i)
            if ((s[i] == 'D' || s[i] == 'd') && (s[i + 1] == 'O' || s[i + 1] == 'o') && (s[i + 2] == 'G' || s[i + 2] == 'g') && (s[i + 3] == 'E' || s[i + 3] == 'e'))
                ++cnt;
    }
    cout << cnt << endl;
    return 0;
}