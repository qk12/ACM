// HDU 1029
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans;
        int cnt = 0;
        while (n--)
        {
            int num;
            scanf("%d", &num);
            if (ans == num)
                ++cnt;
            else
            {
                if (cnt == 0)
                    ans = num;
                else
                    --cnt;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}