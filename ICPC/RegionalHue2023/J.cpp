#include <bits/stdc++.h>
#include <array>
#include <vector>
#include <algorithm>
#define ui unsigned int
using namespace std;

void Solution(int &traps)
{
    vector<array<ui, 3>> listT; // index, first, second
    vector<int> ans;

    int bZero = -1, maxS = -1; // index of (0 x), max(a+b)
    bool aZero = 0;

    for (int i = 0; i < traps; i++)
    {
        ui a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            aZero = 1;
            ans.push_back(i);
        }
        else if (a != 0 && b == 0)
            ans.push_back(i);
        else if (a == 0 && b != 0)
        {
            array<ui, 3> tmp = {0, 0, 0};
            tmp[0] = i;
            tmp[1] = a;
            tmp[2] = b;

            if (bZero == -1)
                bZero = i;
            else if (b > listT[bZero][2])
                bZero = i;

            listT.push_back(tmp);
        }
        else
        {
            array<ui, 3> tmp = {0, 0, 0};
            tmp[0] = i;
            tmp[1] = a;
            tmp[2] = b;

            if (maxS == -1)
                maxS = i;
            else if (a + b > listT[maxS][1] + listT[maxS][2])
                maxS = i;

            listT.push_back(tmp);
        }
    }

    // (0 0) exist
    if (aZero)
    {
        if (bZero != -1)
            ans.push_back(bZero); //(0 x)

        if (maxS != -1)
            ans.push_back(maxS); // (a b)

        for (int i = 0; i < (int)listT.size(); i++)
        {
            if (listT[i][0] == maxS)
                listT.erase(listT.begin() + i);

            else if (listT[i][0] == bZero)
                listT.erase(listT.begin() + i);
        }
    }

    auto compare_b = [](const array<ui, 3> &a, const array<ui, 3> &b)
    {
        return a[2] < b[2];
    };

    sort(listT.begin(), listT.end(), compare_b);

    for (int i = (int)listT.size() - 1; i >= 0; i--)
        ans.push_back(listT[i][0]);

    bool space = 1;
    for (int i = (int)ans.size() - 1; i >= 0; i--)
    {
        if (space)
        {
            cout << ans[i] + 1;
            space = 0;
        }
        else
            cout << " " << ans[i] + 1;
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int traps;
    cin >> traps;
    while (traps > 0)
    {
        Solution(traps);
        cin >> traps;
    }
    return 0;
}