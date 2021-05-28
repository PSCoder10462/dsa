#include <iostream>
#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    std::cin >> T;
    while (T--)
    {

        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        int val = 1;

        for (int i = 1; i < a; ++i)
            val += 1 + i;

        for (int i = 1; i < b; ++i)
            val += a + i - 1;

        int sum = val;

        for (int i = a; i < c; ++i)
        {
            val += (i + b);
            sum += val;
        }

        for (int i = b; i < d; ++i)
        {
            val += (i + c - 1);
            sum += val;
        }

        std::cout << sum << '\n';
    }
    return 0;
}
