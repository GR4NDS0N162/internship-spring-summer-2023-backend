#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

int main()
{
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
    { cin >> ci; }

    unordered_map<int, int> r;
    for (const auto& ci : c)
    { cin >> r[ci]; }

    int k;
    cin >> k;

    int last, current;
    int counter = 0;
    cin >> last;
    for (int i = 1; i != k; ++i)
    {
        cin >> current;
        if (r[last] != r[current])
        { ++counter; }
        last = current;
    }

    cout << counter;
}
