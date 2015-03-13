#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
using namespace std;

int main()
{
    size_t size;
    cin >> size;

    vector<int> v(size);

    copy_n(istream_iterator<int>(cin), size, begin(v));

    int p = v[0];
    stable_partition(begin(v), end(v), [p](int n){ return n < p; });

    for (int n : v)
        cout << n << ' ';
    std::cout << '\n';
}
