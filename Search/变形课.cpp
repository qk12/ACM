// HDU 1181
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1005;
string s[maxn];
bool vis[maxn];
bool flag;
int n;

void dfs(char x, char y)
{
    if (y == 'm')
    {
        flag = true;
        return;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && y == s[i][0])
            {
                vis[i] = true;
                int len = s[i].length();
                dfs(s[i][0], s[i][len - 1]);
                vis[i] = false;
            }
        }
    }
}

int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "0")
        {
            for (int i = 1; i <= n; ++i)
            {
                if (s[i][0] == 'b')
                {
                    int len = s[i].length();
                    vis[i] = true;
                    dfs('b', s[i][len - 1]);
                    vis[i] = false;
                }
            }
            if (flag)
                cout << "Yes." << endl;
            else
                cout << "No." << endl;
            flag = false;
            memset(vis, 0, sizeof(vis));
            n = 0;
        }
        else
        {
            s[++n] = str;
        }
    }
    return 0;
}