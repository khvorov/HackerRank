#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const unsigned long maxSquare = 31623;

    vector<unsigned long> squares(maxSquare);

    auto sb = squares.begin(), se = squares.end();
    {
        int i = 0;
        auto pow2 = [](unsigned long v) -> unsigned long { return v * v; };
        generate(sb, se, [&i, pow2] { return pow2(i++); });
    }

    int T;
    cin >> T;

    vector<pair<unsigned long, unsigned long>> inputs(T);
    for (auto & i : inputs)
        cin >> i.first >> i.second;

    for (auto i : inputs)
    {
        auto lb = lower_bound(sb, se, i.first);
        auto ub = lower_bound(sb, se, i.second);

        auto dist = distance(lb, ub);

        if (ub != se && *ub == i.second)
            ++dist;

        cout << dist << "\n";
    }
}
