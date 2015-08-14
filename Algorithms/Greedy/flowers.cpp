/*
3 3
2 5 6 
==> 13

3 2
2 5 6
==> 15

4 5
1 21 4 7
==> 33

4 2
1 21 4 7
==> 37

7 3
1 2 3 4 5 6 7
1: (0+1)*7 + (1+1)*2 = 7 + 4 = 11
2: (0+1)*6 + (1+1)*3 = 6 + 6 = 12
3: (0+1)*5 + (1+1)*4 + (2+1)*1 = 5 + 8 + 3 = 16
==> 39

7 4
1 2 3 4 5 6 7
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    // read inputs
    int n, k;
    std::cin >> n >> k;

    std::vector<int> c(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, c.begin());

    std::sort(c.begin(), c.end(), std::greater<int>());

    int result = 0, x = 0, cnt = 0;

    for (auto && i : c)
    {
        result += i * (x + 1);

        if (++cnt >= k)
        {
            ++x;
            cnt = 0;
        }
    }

    std::cout << result << '\n';

    return 0;
}
