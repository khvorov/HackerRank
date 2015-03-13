#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    /* The code required to enter n,k, candies is provided*/

    int N, K, unfairness = std::numeric_limits<int>::max();

    cin >> N >> K;
    vector<int> candies(N);
    for (int i = 0; i < N; i++)
    {
        cin >> candies[i];
    }

    sort(begin(candies), end(candies));

    for (auto i = begin(candies), iK = next(i, K - 1), iEnd = end(candies); iK != iEnd; ++i, ++iK)
    {
        unfairness = std::min(unfairness, *iK - *i);
    }

    cout << unfairness << "\n";
    return 0;
}
