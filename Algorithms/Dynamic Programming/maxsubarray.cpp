/*
testcases:

5
9
-2 1 -3 4 -1 2 1 -5 4
6
2 -1 2 3 4 -5
4
1 2 3 4
6
0 0 -3 0 -5 0
2
-3 -5
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

template <typename I, typename R = typename std::iterator_traits<I>::value_type>
R max_contigious_subarray(I f, I l)
{
    R max_ending_here(*f++);
    R max_so_far(max_ending_here);

    for (; f != l; ++f)
    {
        max_ending_here = std::max(max_ending_here + *f, *f);
        max_so_far = std::max(max_ending_here, max_so_far);
    }

    return max_so_far;
}

template <typename I, typename R = typename std::iterator_traits<I>::value_type>
R max_non_contigious_subarray(I f, I l)
{
    R maxSum(0), maxNegativeElement(std::numeric_limits<R>::min());
    bool isNegativeResult = true;

    for (; f != l; ++f)
    {
        if (*f >= 0)
        {
            maxSum += *f;
            isNegativeResult = false;
        }
        else if (isNegativeResult)
        {
            maxNegativeElement = std::max(maxNegativeElement, *f);
        }
    }

    if (isNegativeResult)
        return maxNegativeElement;

    return maxSum;
}

int main()
{
    int testsCount;
    std::cin >> testsCount;

    while (--testsCount >= 0)
    {
        std::size_t N;
        std::cin >> N;

        std::vector<int> inputs(N);
        std::copy_n(std::istream_iterator<int>(std::cin), N, inputs.begin());

        std::cout << max_contigious_subarray(inputs.begin(), inputs.end()) << " "
                  << max_non_contigious_subarray(inputs.begin(), inputs.end()) << "\n";

    }

    return 0;
}
