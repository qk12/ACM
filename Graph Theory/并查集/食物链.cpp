// POJ 1182
#include <cstdio>
using namespace std;

const int maxn = 100005;
int N, K;
int T[maxn], X[maxn], Y[maxn]; //T[i]存储类型信息
int father[150005];
void init(int n)
{
    for (int i = 0; i < n; ++i)
        father[i] = i;
}
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    father[x] = y;
}
bool same(int x, int y) { return find(x) == find(y); }
int solve()
{
    init(3 * N); //初始化并查集。元素x, x+N, x+2*N分别代表x-A, x-B, x-C
    int ans = 0;
    for (int i = 0; i < K; ++i)
    {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;         //把输入变成0~N-1的范围
        if (x < 0 || x >= N || y < 0 || y >= N) //越界的编号
        {
            ++ans;
            continue;
        }
        if (t == 1) //x和y属于同一类
        {
            if (same(x, y + N) || same(x, y + 2 * N)) //判断是否矛盾
                ++ans;
            else
            {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        else //x吃y
        {
            if (x == y || same(x, y) || same(x, y + 2 * N)) //判断是否矛盾
                ++ans;
            else
            {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; ++i)
        scanf("%d%d%d", &T[i], &X[i], &Y[i]);
    printf("%d\n", solve());
    return 0;
}