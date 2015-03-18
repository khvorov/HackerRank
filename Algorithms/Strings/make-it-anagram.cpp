/*
input:
fsqoiaidfaukvngpsugszsnseskicpejjvytviya
ksmfgsxamduovigbasjchnoskolfwjhgetnmnkmcphqmpwnrrwtymjtwxget

output:
42
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::string A, B;

    std::getline(std::cin, A);
    std::getline(std::cin, B);

    // 26 letters of English alphabet
    std::vector<int> letters(26, 0);

    for (auto a : A)
        ++letters[a - 'a'];

    for (auto b : B)
        --letters[b - 'a'];

    int result = std::accumulate(letters.begin(),
                                 letters.end(), 0,
                                 [](int v, int a)
                                 {
                                    return v + abs(a);
                                 });

    std::cout << result << "\n";

    return 0;
}
