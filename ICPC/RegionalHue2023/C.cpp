#include <bits/stdc++.h>
using namespace std;

int mask[6][2] = {{-1, 0}, {1, 0}, {0, 1}, {1, 1}, {-1, -1}, {0, -1}};
/*
Một sô được tô bằng cách dùng 1 ngôi sao tâm là chính nó, r = 3
và 6 ngôi sao có tâm là 6 ô xung quanh, r = 2*/

void Solution()
{
    int n;
    cin >> n;

    cout << "YES\n";
    cout << 7 * n << endl;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << x << " " << y << " 3\n";
        for (int j = 0; j < 6; j++)
        {
            cout << x + mask[j][0] << " " << y + mask[j][1] << " 2\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
        Solution();

    return 0;
}
