#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	int lb, ub;
	lb = ub = v[0];

	int amazing = 0;
	for (auto x : v)
	{
		if (x > ub)
		{
			ub = x;
			amazing++;
		}
		if (x < lb)
		{
			lb = x;
			amazing++;
		}
	}

	std::cout << amazing;

	return 0;
}
