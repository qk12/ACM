#include <bits/stdc++.h>
using namespace std;

unordered_set<string> S;
string str, s;
int main()
{
    while (getline(cin, str) && str[0] != '#')
    {
        stringstream ss(str);
        while (ss >> s)
            S.insert(s);
        printf("%d\n", (int)S.size());
        S.clear();
    }
    return 0;
}