// POJ 3253
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, L;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        cin >> L;
        pq.push(L);
    }
    long long ans = 0;
    while (pq.size() > 1)
    {
        int L1 = pq.top();
        pq.pop();
        int L2 = pq.top();
        pq.pop();
        ans += L1 + L2;
        pq.push(L1 + L2);
    }
    cout << ans << endl;
    return 0;
}
