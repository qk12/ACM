// Luogu 1522
#include <bits/stdc++.h>
using namespace std;

const double INF = 1e12;
const int maxn = 155;
double temp[maxn], dis[maxn][maxn];
int x[maxn], y[maxn];
int n;

double dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void floyd_warshall()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    char c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> c;
            if (c == '1')
                dis[i][j] = dist(i, j);
            else if (i != j)
                dis[i][j] = INF;
        }

    floyd_warshall();

    double max1 = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (fabs(dis[i][j] - INF) > 1)
                temp[i] = max(dis[i][j], temp[i]);
            max1 = max(max1, temp[i]);
        }

    double max2 = INF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (fabs(dis[i][j] - INF) < 1)
            {
                max2 = min(temp[i] + dist(i, j) + temp[j], max2);
            }

    double ans = max(max1, max2);
    printf("%.6lf\n", ans);

    return 0;
}
