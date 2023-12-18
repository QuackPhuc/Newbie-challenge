#include <bits/stdc++.h>
#include <array>
#include <vector>
#include <algorithm>
#define ui unsigned int
using namespace std;

auto compare_s = [](const array<ui, 3> &a, const array<ui, 3> &b)
{
    if (a[2] < b[2])
        return true;
    if (a[2] == b[2] && a[1] < b[1])
        return true;
    else
        return false;
};

auto compare_b = [](const array<ui, 3> &a, const array<ui, 3> &b)
{
    return a[2] < b[2];
};

void Solution(int &traps)
{
    // array<index, a, a + b>
    vector<array<ui, 3>> bZ;    // (0 x)
    vector<array<ui, 3>> other; // (x y)
    vector<int> ans;

    int aZ = 0; // count (0 0)

    for (int i = 0; i < traps; i++)
    {
        ui a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            aZ++;
            ans.push_back(i);
        }
        else if (a != 0 && b == 0)
        {
            ans.push_back(i);
        }
        else if (a == 0 && b != 0)
        {
            array<ui, 3> tmp = {(ui) i, a, a + b};
            bZ.push_back(tmp);
        }
        else
        {
            array<ui, 3> tmp = {(ui) i, a, a + b};
            other.push_back(tmp);
        }
    }

    if (aZ > 0)
    {
        sort(other.begin(), other.end(), compare_s);

        while (!bZ.empty())
        {
            int tmp = (int) bZ.back()[0];
            ans.push_back(tmp);
            bZ.pop_back();
        }

        while (aZ > 1)
        {
            if (!other.empty())
            {
                int tmp = (int)other.back()[0];
                ans.push_back(tmp);
                other.pop_back();
            }
            aZ--;
        }

        if (other.size() > 1)
        {
            array<ui, 3> a = other.back();
            array<ui, 3> b = other[other.size() - 2];

            sort(other.begin(), other.end(), compare_b);
            array<ui, 3> c = other.back();
            array<ui, 3> d = other[other.size() - 2];

            if (a[2] + d[2] - d[1] > b[2] + c[2] - c[1])
            {
                ans.push_back((int)a[0]);
                ans.push_back((int)d[0]);
                other.erase(std::remove(other.begin(), other.end(), a), other.end());
                other.erase(std::remove(other.begin(), other.end(), d), other.end());
            }
            else
            {
                ans.push_back((int)b[0]);
                ans.push_back((int)c[0]);
                other.erase(std::remove(other.begin(), other.end(), b), other.end());
                other.erase(std::remove(other.begin(), other.end(), c), other.end());
            }

            while (!other.empty())
            {
                int tmp = (int)other.back()[0];
                ans.push_back(tmp);
                other.pop_back();
            }
        }
        else if (other.size() == 1)
        {
            ans.push_back(other.back()[0]);
        }
    }
    else
    {
        other.insert(other.end(), bZ.begin(), bZ.end());
        sort(other.begin(), other.end(), compare_b);

        while (!other.empty())
        {
            int tmp = (int) other.back()[0];
            ans.push_back(tmp);
            other.pop_back();
        }
    }

    for (int i = (int)ans.size() - 1; i >= 0; i--)
    {
        if (i == (int)ans.size() - 1)
        {
            cout << ans[i] + 1;
        }
        else
        {
            cout << " " << ans[i] + 1;
        }
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