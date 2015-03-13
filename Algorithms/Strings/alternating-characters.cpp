#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<string> inputs(N);
    for (auto & i : inputs)
        cin >> i;

    for (auto i : inputs)
    {
        size_t count = 0;
        for (auto f = next(i.begin()), l = i.end(), s = i.begin(); f != l; ++f)
        {
            if (*f == *s)
                ++count;
            else
                s = f;
        }
        
        cout << count << "\n";
    }

    return 0;
}
