// HDU 5934
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int n;
int dfn[maxn], low[maxn];
int scc[maxn]; //节点所在强联通分量编号
int idx;
int sccnum;             //联通分量总数
vector<int> edge[maxn]; //邻接表，从1开始
stack<int> st;          //栈，可改为手写栈
int ind[maxn];
int x[maxn], y[maxn], r[maxn];
int c[maxn];

void dfs(int x)
{
    dfn[x] = low[x] = ++idx;
    st.push(x);
    for (int i = 0; i < edge[x].size(); ++i)
    {
        int s = edge[x][i];
        if (!dfn[s])
        { //指向子节点则递归子节点后更新自己
            dfs(s);
            low[x] = min(low[s], low[x]);
        }
        else if (!scc[s])
        { //指向父亲（指向栈外父亲不做操作，指向栈内父亲进行更新）
            low[x] = min(dfn[s], low[x]);
        }
    }
    if (low[x] == dfn[x]) //统计信息
    {
        ++sccnum;
        while (true)
        {
            int tmp = st.top();
            st.pop();
            scc[tmp] = sccnum;
            if (tmp == x)
                break;
        }
    }
}
int tarjan()
{
    sccnum = idx = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(scc, 0, sizeof(scc));
    memset(ind, 0, sizeof(ind));
    while (!st.empty())
        st.pop();
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            dfs(i); //只有没访问过的点需要dfs
    }
    return sccnum; //强联通分量数
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            edge[i].clear();
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", &x[i], &y[i], &r[i], &c[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                if (1LL * r[i] * r[i] >= (1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j])))
                    edge[i].push_back(j);
            }
        int res = tarjan();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < edge[i].size(); ++j)
            {
                int s = edge[i][j]; //i->s
                if (scc[i] != scc[s])
                {
                    ++ind[scc[s]];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= res; ++i)
            if (ind[i] == 0)
            {
                int temp = 1e9;
                for (int j = 1; j <= n; ++j)
                {
                    if (scc[j] == i)
                    {
                        temp = min(temp, c[j]);
                    }
                }
                ans += temp;
            }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}