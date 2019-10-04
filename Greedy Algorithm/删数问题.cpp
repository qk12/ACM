// Luogu 1106
#include <bits/stdc++.h>
using namespace std;

string n;
int s;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> s;
        int len = n.length();
        while (s--)
        {
            for (int i = 0; i < len - 1; i++)
            {
                if (n[i] > n[i + 1])
                {
                    for (int j = i; j < len - 1; j++) //将n[i]移到数组最后
                        n[j] = n[j + 1];
                    break;
                }
            }
            len--;
        }
        int k = 0;
        while (k < len && n[k] == '0') //处理前导0
            k++;
        if (k == len)
            cout << "0";
        else
            for (int i = k; i < len; i++)
                cout << n[i];
        cout << endl;
    }
    return 0;
}