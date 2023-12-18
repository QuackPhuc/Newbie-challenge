#include <bits/stdc++.h>
#include <vector>

using namespace std;

void Solution()
{
    /*
    team1 dùng phép hoặc, team1[i] == 0 => team này không giải được bài nào
    team2 dùng phép và, team2[i] == 1 => team này giải được tất cả các bài
    problem tương tự team1
    */
    int m, n;
    bool tmp;
    cin >> m >> n;

    vector<bool> team1(m, 0);
    vector<bool> team2(m, 1);
    vector<bool> problem(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            problem[j] = tmp || problem[j];
            team1[i] = team1[i] || tmp;
            team2[i] = team2[i] && tmp;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (!problem[j])
        {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (!team1[i])
        {
            cout << "NO\n";
            return;
        }

        if (team2[i])
        {
            cout << "NO\n";
            return;
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