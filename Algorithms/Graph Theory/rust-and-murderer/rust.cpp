/*
d: g++ -m32 -Wall -Werror -pedantic -std=c++11 -O0 -g -fsanitize=address rust.cpp && ./a.out < input
r: g++ -m32 -Wall -Werror -pedantic -std=c++11 -O3 -march=native rust.cpp && ./a.out < input

2 2 1
1 1 1 2 1
3 1 1 2 2
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

using list_t = std::vector<int>;
using adjacent_list_t = std::vector<list_t>;

void dijkstra(const adjacent_list_t & al, std::size_t source, list_t & dist)
{
    static const int cInf = std::numeric_limits<int>::max() - 1;
    const std::size_t N = al.size();

    dist.resize(N, 1); // as graph is an "almost complete" we assume that most of vertices are incident to the source node
    dist[source] = 0;

    std::deque<int> q;

    for (auto && n : al[source])
    {
        dist[n] = cInf;
        q.push_back(n);
    }

    while (!q.empty())
    {
        auto current = q.front();
        q.pop_front();

        const auto & currentAl = al[current];
        auto b = currentAl.begin(), e = currentAl.end();

        bool found = false;
        int min = cInf;

        for (std::size_t n = 0; n < N; ++n)
        {
            if (std::find(b, e, n) == e && dist[n] != cInf)
            {
                min = std::min(min, dist[n]);
                found = true;
            }
        }

        if (found)
            dist[current] = min + 1;
        else
            q.push_back(current);
    }
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        // number of cities and number of main roads in the map
        int N, M;
        std::cin >> N >> M;

        // getting adjacency list for the graph of main roads
        adjacent_list_t mainRoads(N);

        while (M--)
        {
            int a, b;
            std::cin >> a >> b;

            --a; --b;
            mainRoads[a].push_back(b);
            mainRoads[b].push_back(a);
        }

        // reading current position of Mr. Rust
        int S;
        std::cin >> S;

        list_t dist;
        dijkstra(mainRoads, --S, dist);

        std::copy_if(dist.begin(), dist.end(),
            std::ostream_iterator<int>(std::cout, " "),
            [](int i) { return i != 0; });

        std::cout << "\n";
    }

    return 0;
}
