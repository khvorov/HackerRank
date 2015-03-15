#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

using cmd_map_t = std::map<const char, std::function<void (std::string &)>>;

int main()
{
    const cmd_map_t commands = {
        {'C', [](std::string & s)
        {
            std::size_t l, r;
            char c;
            std::cin >> l >> r >> c;

            auto f = std::begin(s);
            std::fill(std::next(f, --l), std::next(f, r), c);
        }},
        {'S', [](std::string & s)
        {
            std::size_t l1, r1, l2, r2;
            std::cin >> l1 >> r1 >> l2 >> r2;

            auto f = std::begin(s);
            if (l2 - r1 - 1 > 0)
                std::rotate(f + r1, f + l2 - 1, f + r2);
            std::rotate(f + l1 - 1, f + r1, f + r2);
        }},
        {'R', [](std::string & s)
        {
            std::size_t l, r;
            std::cin >> l >> r;

            auto f = std::begin(s);
            std::reverse(std::next(f, --l), std::next(f, r));
        }},
        {'W', [](std::string & s)
        {
            std::size_t l, r;
            std::cin >> l >> r;

            auto f = std::begin(s);
            std::copy(std::next(f, --l), std::next(f, r), std::ostream_iterator<char>(std::cout, ""));
            std::cout << "\n";
        }},
        {'H', [](std::string & s)
        {
            std::size_t l1, l2, len;
            std::cin >> l1 >> l2 >> len;

            auto f = std::begin(s);
            auto b1 = std::next(f, --l1), e1 = std::next(f, l1 + len),
                 b2 = std::next(f, --l2);

            std::size_t result = 0;
            for (; b1 != e1; ++b1, ++b2)
            {
                if (*b1 != *b2)
                    ++result;
            }

            std::cout << result << "\n";
        }}
    };

    std::size_t N;
    std::cin >> N;

    std::string s;
    s.reserve(N);
    std::cin >> s;

    std::size_t M;
    std::cin >> M;

    while (M--)
    {
        char c;
        std::cin >> c;

        auto cmd = commands.find(c);
        if (cmd != commands.end())
        {
            cmd->second(s);
        }
        else
        {
            std::cerr << "unknown command: " << c << "\n";
        }
    }

    return 0;
}
