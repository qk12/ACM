// POJ 1426
#include <iostream>
using namespace std;

bool flag;

void dfs(int n, unsigned long long state, int len)
{
    if (flag || len == 19)
        return;
    if (state % n == 0)
    {
        flag = true;
        cout << state << endl;
        return;
    }
    dfs(n, state * 10, len + 1);
    dfs(n, state * 10 + 1, len + 1);
    return;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        flag = false;
        dfs(n, 1, 0);
    }
}