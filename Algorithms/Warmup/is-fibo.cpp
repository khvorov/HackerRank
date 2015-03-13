#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
    // read input (T and numbers)
    std::size_t T;
    std::cin >> T;

    std::vector<unsigned long long> inputs(T);
    for (auto &i : inputs)
        std::cin >> i;

    // init vector
    int n = 51; // that should be enough based on pre-conditions and Binet's formula
    std::vector<unsigned long long> fibs(n);

    fibs[0] = 0; fibs[1] = 1;

    for (std::size_t i = 2; i < fibs.size(); ++i)
        fibs[i] = fibs[i - 1] + fibs[i - 2];

    auto bf = std::begin(fibs), ef = std::end(fibs);

    for (auto i : inputs)
    {
        if (std::binary_search(bf, ef, i))
            std::cout << "IsFibo\n";
        else
            std::cout << "IsNotFibo\n";
    }

    return 0;
}
