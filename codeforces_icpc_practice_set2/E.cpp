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

	int child = 2;

	for (int i = 1; i <= n - 1; ++i)
	{
		std::cout << child << " ";
		child += (i + 1);
		if (child > n)
			child -= n;
	}

	return 0;
}
