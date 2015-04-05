#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

std::size_t z_algo(const std::string & s)
{
    std::size_t n = s.size();
    std::vector<std::size_t> z(n, 0);

    std::size_t L = 0, R = 0;
    for (std::size_t i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            z[i] = R - L; R--;
        }
        else
        {
            std::size_t k = i - L;
            if (z[k] < R - i + 1)
                z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R - L] == s[R])
                    R++;
                z[i] = R - L; R--;
            }
        }
    }

    return std::accumulate(z.begin(), z.end(), n);
}

int main()
{
    std::size_t T;
    std::cin >> T;

    while (T--)
    {
        std::string s;
        std::cin >> s;

        std::cout << z_algo(s) << "\n";
    }

    return 0;
}