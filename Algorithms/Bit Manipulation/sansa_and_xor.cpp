#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    size_t T;
    cin >> T;

    vector<vector<int>> inputs(T);
    for (auto & i : inputs)
    {
        size_t N;
        cin >> N;

        i.reserve(N);
        copy_n(istream_iterator<int>(cin), N, back_inserter(i));
    }

    for (auto & i : inputs)
    {
        if (i.size() % 2)
        {
            size_t idx = 0;
            cout << accumulate(begin(i), end(i), 0, [&idx](int acc, int x) { return (++idx % 2) ? (acc ^ x) : acc; }) << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}
