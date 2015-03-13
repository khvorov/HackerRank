#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<unsigned int> elements(N);

    for (int i = 0; i < N; i++)
        cin >> elements[i];

    for (auto i : elements)
        cout << (~i) << "\n";

    return 0;
}