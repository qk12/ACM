// POJ 2387
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const int max_v = 35;
double dis[max_v][max_v];
double floyd(int n)
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = max(dis[i][j], dis[i][k] * dis[k][j]);
    double res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, dis[i][i]);
    return res;
}

int main()
{
    string s, x, y;
    int V, E;
    int kase = 0;
    while (cin >> V, V)
    {
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
            {
                if (i == j)
                    dis[i][j] = 1;
                else
                    dis[i][j] = 0;
            }
        map<string, int> mp;
        for (int i = 0; i < V; ++i)
        {
            cin >> s;
            mp[s] = i;
        }
        cin >> E;
        double temp;
        while (E--)
        {
            cin >> x >> temp >> y;
            dis[mp[x]][mp[y]] = temp;
        }
        double ans = floyd(V);
        if (ans > 1)
            cout << "Case " << ++kase << ": Yes" << endl;
        else
            cout << "Case " << ++kase << ": No" << endl;
    }
    return 0;
}
