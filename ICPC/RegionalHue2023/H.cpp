#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
D = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"}
D' = {
    "+", (ASCII 43)
    "/", (47)
    "0123456789", (ASCII 48 - 57)
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", (65 - 90)
    "abcdefghijklmnopqrstuvwxyz", (97 - 122)
}
*/

void Solution()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    //decode
    string b;
    for (int i = 0; i < (int) s.size(); i++)
    {
        int d; 
        if (s[i] < '/')
            d = 62;
        else if (s[i] < '0')
            d = 63;
        else if (s[i] < 'A')
            d = s[i] - '0' + 52; 
        else if (s[i] < 'a')
            d = s[i] - 'A';
        else
            d = s[i] - 'a' + 26;

        string c = bitset<6>(d).to_string();
        reverse(c.begin(), c.end());
        b += c;
    }

    // matrix a nxn
    vector<string> a;
    for (int i = 0; i < n; i++)
        a.push_back(b.substr(i*n, n));

    // compare row by A
    hash<string> hashA;
    vector<size_t> A(n);
    for (int i = 0; i < n; i++)
        A[i] = hashA(a[i]);
    
    //Tìm 3 ô '0', 1 ô '1'
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    for (int j = 0; j < n; j++)
    {
        bool conti = true;
        x1 = -1; 
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 48)
            {
                if (x1 == -1)
                    x1 = i;
                else if (A[i] != A[x1])
                {
                    conti = false;
                    x2 = i;
                    y1 = j;
                    break;
                }
            }
        }

        if (!conti)
            break;
    }

    if (x2 != -1)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[x1][j] != a[x2][j])
            {
                y2 = j;
                break;
            }
        }
        cout << "YES\n";
        cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
    }
    else
        cout << "NO\n";
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