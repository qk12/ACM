// POJ 3041
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int max_v = 1005;
vector<int> G[max_v];
int linker[max_v];
bool vis[max_v];
inline void init(int n)
{
    for (int i = 0; i < n; ++i)
        G[i].clear();
}
inline void addedge(int u, int v) { G[u].push_back(v); }
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(int n)
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int i = 0; i < n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            ++res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    init(n);
    int x,y;
    while (k--)
    {
       cin>>x>>y;
        addedge(x-1,y-1);
    }
    cout<<hungary(n)<<endl;
    return 0;
}