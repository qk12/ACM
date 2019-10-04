#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e4 + 5;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int uN, vN, dis;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
bool used[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
inline void addedge(int u, int v) { G[u].push_back(v); }
bool bfs()
{
    queue<int> q;
    dis = INF;
    memset(dx, -1, sizeof(dx)), memset(dy, -1, sizeof(dy));
    for (int i = 0; i < uN; i++)
        if (Mx[i] == -1)
            q.push(i), dx[i] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dx[u] > dis)
            break;
        for (auto &v : G[u])
        {
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool dfs(int u)
{
    for (auto &v : G[u])
    {
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis)
                continue;
            if (My[v] == -1 || dfs(My[v]))
            {
                My[v] = u, Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof(Mx)), memset(My, -1, sizeof(My));
    while (bfs())
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < uN; i++)
            if (Mx[i] == -1 && dfs(i))
                res++;
    }
    return res;
}

const int max_num = 5e5 + 5;
int a[max_num];
int sz[max_num];
int prime[5000]; //prime[0]储存素数的个数，素数下标从1开始
bool is_prime[max_num];

void getPrime(int n)
{
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[++prime[0]] = i;
            sz[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
        {
            is_prime[i * prime[j]] = false; //找到的素数的倍数不访问
            sz[i * prime[j]] = sz[i] + 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int ind[max_num];

int main()
{
    getPrime(500000);
    int T;
    scanf("%d", &T);
    int n;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d", &n);
        init(n);
        uN = vN = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);
        memset(ind, -1, sizeof(ind));
        int lim = 0;
        for (int i = 0; i < n; ++i)
        {
            lim = max(lim, a[i]);
            if (sz[a[i]] & 1)
                ind[a[i]] = uN++;
            else
                ind[a[i]] = vN++;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 1; j <= prime[0] && a[i] * prime[j] <= lim; ++j)
            {
                if (ind[a[i] * prime[j]] != -1)
                {
                    if (sz[a[i]] & 1)
                        addedge(ind[a[i]], ind[a[i] * prime[j]]);
                    else
                        addedge(ind[a[i]] * prime[j], ind[a[i]]);
                }
            }
        printf("Case %d: %d\n", k, n - MaxMatch());
    }
    return 0;
}