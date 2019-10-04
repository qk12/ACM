// POJ 3617
#include <iostream>
using namespace std;

int n;
char s[2005], ans[2005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int l = 0, r = n - 1; //剩余的字符串为S[a],S[a+1],...,S[b]
    int cnt = 0;
    while (l <= r) //将从左起和从右起的字符串比较
    {
        bool left = false;
        for (int i = 0; l + i <= r; ++i)
            if (s[l + i] < s[r - i])
            {
                left = true;
                break;
            }
            else if (s[l + i] > s[r - i])
            {
                left = false;
                break;
            }
        ans[cnt++] = left ? s[l++] : s[r--];
    }
    for (int i = 0; i < n; ++i)
    {
        if (i % 80 == 0 && i != 0)
            cout << endl;
        cout << ans[i];
    }
    return 0;
}