#include <bits/stdc++.h>
#include <string>

using namespace std;

void Solution()
{
    /*
    Xoay một chuỗi có độ dài lẻ => vị trí các ký tự giữ nguyên tính chẵn hay lẻ
    Chuỗi A có thể xoay thành B khi các ký tự ở index lẻ của A cũng ở index lẻ ở B. Tương tự với index chẵn
    */

    string a, b;
    cin >> a >> b;

    if (a.length() != b.length())
    {
        cout << "NO\n";
        return;
    }

    unordered_map<char, long unsigned int> charCountOdd;
    unordered_map<char, long unsigned int> charCountEven;

    for (int i = 0; i < a.length(); i++)
    {
        if (i % 2 == 0)
            charCountOdd[a[i]]++;
        else
            charCountEven[a[i]]++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (charCountOdd.find(b[i]) == charCountOdd.end() || charCountOdd[b[i]] == 0)
            {
                cout << "NO\n";
                return;
            }
            charCountOdd[b[i]]--;
        }
        else
        {
            if (charCountEven.find(b[i]) == charCountEven.end() || charCountEven[b[i]] == 0)
            {
                cout << "NO\n";
                return;
            }
            charCountEven[b[i]]--;
        }
    }
    cout << "YES\n";
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
