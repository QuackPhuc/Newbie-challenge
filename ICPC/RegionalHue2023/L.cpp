#include <bits/stdc++.h>
using namespace std;

void Solution()
{
    /* 
    Với n = 1xxx...xxx (m - 1 số phía sau chữ số 1)
    nếu trong xxx...xxx có một số 1 thì đồ thị liên thông.
    Vì từ 0 đến n thì có 111...111 (m - 1 số 1), vậy nên m - 1 đỉnh ấy liên thông. Chỉ cần đỉnh đầu và một đỉnh    khác liên thông thì cả đồ thị liên thông.

    VD:
    n = 10100
    từ 0 đến n có:
    1
    10
    11
    ...
    1110
    1111
    10100
    ta có 1111 => đỉnh 2 đến đỉnh 5 liên thông với nhau
    10100 => đỉnh 1 và đỉnh 3 liên thông.
    => đồ thị liên thông.
    */

    int m;
    cin >> m;

    string n;
    cin >> n;

    if (m > n.length())
    {
        cout << "NO\n";
        return;
    }
    else if (n.length() > m)
    {
        cout << "YES\n";
        return;
    }
    else if (m == 1)
    {
        if (n[0] >= '0')
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    else
    {
        for (int i = 1; i < n.length(); i++)
        {
            if (n[i] == '1')
            {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
