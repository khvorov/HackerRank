#include <iostream>

int main()
{
    std::size_t T;
    std::cin >> T;

    while (T-- > 0)
    {
        std::size_t N;
        std::cin >> N;

        int result = 1;
        while (--N > 0)
        {
            int ni;
            std::cin >> ni;
            result *= ni;
            result %= 1234567;
        }

        std::cout << result << "\n";
    }

    return 0;
}
