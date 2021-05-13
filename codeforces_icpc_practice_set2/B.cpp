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
	int n, d;
	std::cin >> n >> d;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	std::sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (v[j] - v[i] <= d)
				ans++;
			else
				break;
		}
	}

	std::cout << ans * 2;
	return 0;
}
