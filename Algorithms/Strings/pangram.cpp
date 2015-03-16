#include <cctype>
#include <iostream>
#include <string>

int main()
{
    const unsigned long mask = 0x3FFFFFF;

    std::string s;
    std::getline(std::cin, s);

    unsigned long result = 0;
    for (char c : s)
    {
        if (std::isalpha(c))
            result |= (1 << (std::tolower(c) - 'a'));
        
        if (result == mask)
            break;
    }

    if (result == mask)
        std::cout << "pangram\n";
    else
        std::cout << "not pangram\n";

    return 0;
}
