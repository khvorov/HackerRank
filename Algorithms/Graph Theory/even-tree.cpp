#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

using children_t = std::vector<std::size_t>;
using adjacent_list_t = std::vector<std::deque<int>>;

int get_child_count(const adjacent_list_t & al, children_t & children, int root)
{
    std::size_t result = 1;

    for (const auto & c : al[root])
        result += get_child_count(al, children, c);;

    children[root] = result;

    return result;
}

int main()
{
    size_t nVertices, nEdges;
    cin >> nVertices >> nEdges;

    adjacent_list_t adjacentList(nVertices);

    for (size_t i = 0; i < nEdges; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;

        adjacentList[b].emplace_back(a);
    }

    children_t children(nVertices, 0);
    get_child_count(adjacentList, children, 0);

    auto result = count_if(begin(children), end(children), [](int i) -> bool { return i % 2 == 0; }) - 1;
    cout << result << "\n";

    return 0;
}
