#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename I>
void print(I b, I e)
{
    std::copy(b, e, std::ostream_iterator<decltype(*b)>(std::cout, " "));
    std::cout << '\n';
}

template <typename I>
void quicksort(I b, I e)
{
    using value_type = typename std::iterator_traits<I>::value_type;

    if (std::distance(b, e) > 1)
    {
        const value_type & v = *b;
        auto m = stable_partition(b, e, [v](const value_type & n) -> bool { return n < v; });

        quicksort(b, m++);
        quicksort(m, e);

        print(b, e);
    }
}

int main()
{
    size_t size;
    cin >> size;

    vector<int> v(size);

    copy_n(istream_iterator<int>(cin), size, begin(v));

    if (size != 1)
        quicksort(begin(v), end(v));
    else
        print(begin(v), end(v));
}