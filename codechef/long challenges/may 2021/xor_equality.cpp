#include <iostream>
#include <vector>
#define mod 1000000007

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    std::cin >> T;
    std::vector<int> v(100001);
    v[0] = 1;
    for (int i = 0; i < 100000; ++i)
        v[i + 1] = (2 * (v[i] % mod)) % mod;

    while (T--)
    {
        int n;
        std::cin >> n;
        std::cout << v[n - 1] << '\n';
    }

    return 0;
}
