// POJ 2484
// 作出对称的状态后再完全模仿对手的策略
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        if (n <= 2)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}