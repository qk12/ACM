// POJ 2311
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int maxn = 205;
int sg[maxn][maxn];

int SG(int w, int h)
{
    if (sg[w][h] != -1)
        return sg[w][h];
    set<int> s;
    for (int i = 2; w - i >= 2; ++i)
    {
        s.insert(SG(i, h) ^ SG(w - i, h));
    }
    for (int i = 2; h - i >= 2; ++i)
    {
        s.insert(SG(w, i) ^ SG(w, h - i));
    }
    int g = 0;
    while (s.count(g))
        ++g;
    return sg[w][h] = g;
}

int main()
{
    memset(sg, -1, sizeof(sg));
    int w, h;
    while (scanf("%d%d", &w, &h) != EOF)
    {
        if (SG(w, h))
            puts("WIN");
        else
            puts("LOSE");
    }
    return 0;
}