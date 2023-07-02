#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

struct Sculpture
{
    int weight;
    int index;
};

int main()
{
    int n, x;
    long long t;
    cin >> n >> x >> t;

    vector<Sculpture> a(n);
    for (int i = 0; i != n; ++i)
    {
        cin >> a[i].weight;
        a[i].index = i + 1;
    }

    sort(a.begin(), a.end(), [x](const auto& lhs, const auto& rhs) {
        return abs(lhs.weight - x) < abs(rhs.weight - x);
    });

    vector<int> b;
    for (size_t i = 0; i != n; ++i)
    {
        t -= abs(a[i].weight - x);
        if (t >= 0)
        { b.push_back(a[i].index); }
        else
        { break; }
    }

    cout << b.size() << "\n";
    for (const auto& bi : b)
    { cout << bi << " "; }
}
