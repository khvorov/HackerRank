#include <iostream>

int solve(int n, int k)
{
    int r = n % k;
    int g2 = k - r;
    int sz1 = n / k + 1;
    int sz2 = n / k;
    int ret = r * sz1 * g2 * sz2 + r * (r - 1) * sz1 * sz1 / 2 + g2 * (g2 - 1) * sz2 * sz2 / 2;
    return ret;
}

int min_clique_size(int n, int e)
{
    int low = 1, high = n + 1;

    while (low + 1 < high)
    {
        int mid = low + (high - low) / 2;
        int k = solve(n, mid);

        if (k < e)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N, M;
        std::cin >> N >> M;

        std::cout << min_clique_size(N, M) << "\n";
    }

    return 0;
}
