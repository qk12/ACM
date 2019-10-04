// HDU 2767
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5;
int n;
int dfn[maxn], low[maxn];
int scc[maxn]; //节点所在强联通分量编号
int idx;
int sccnum;             //联通分量总数
vector<int> edge[maxn]; //邻接表，从1开始
stack<int> st;          //栈，可改为手写栈

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
    if (low[x] == dfn[x])
    { //统计信息
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
    while (!st.empty())
        st.pop();
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            dfs(i); //只有没访问过的点需要dfs
    }
    return sccnum; //强联通分量数
}
int outd[maxn];
int ind[maxn];

int main()
{
    int m, x1, x2;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            edge[i].clear();
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x1, &x2);
            edge[x1].push_back(x2);
        }
        memset(outd, 0, sizeof(outd));
        memset(ind, 0, sizeof(ind));
        int res = tarjan();
        if (res == 1)
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < edge[i].size(); ++j)
            {
                int s = edge[i][j];
                if (scc[i] != scc[s])
                {
                    ++outd[scc[i]];
                    ++ind[scc[s]];
                }
            }
        }
        int outcnt = 0, incnt = 0;
        for (int i = 1; i <= sccnum; ++i)
        {
            if (outd[i] == 0)
                ++outcnt;
            if (ind[i] == 0)
                ++incnt;
        }
        printf("%d\n", max(outcnt, incnt));
    }
    return 0;
}