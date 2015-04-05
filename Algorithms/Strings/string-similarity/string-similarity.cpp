#include <iostream>
#include <string>

std::size_t similarity(const std::string &s)
{
    std::size_t result = s.size();

    for (auto i = ++s.begin(), iEnd = s.end(); i != iEnd; ++i)
    {
        for (auto j = i, jEnd = s.end(), k = s.begin(); j != jEnd && *j == *k; ++j, ++k, ++result) {}
    }

    return result;
}

int main()
{
    std::size_t T;
    std::cin >> T;

    while (T--)
    {
        std::string s;
        std::cin >> s;

        std::cout << similarity(s) << "\n";
    }

    return 0;
}
