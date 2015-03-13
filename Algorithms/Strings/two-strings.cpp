#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<pair<string, string>> inputs(T);
    for (auto & i : inputs)
        cin >> i.first >> i.second;

    for (auto i : inputs)
    {
        vector<bool> count(256, false);
        for (auto & c : i.first)
            count[c] = true;

        bool result = false;
        for (auto & c : i.second)
        {
            if (count[c])
            {
                result = true;
                break;
            }
        }

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
