#include <iostream>
#include <vector>
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

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		for (int j = i; j < n; ++j)
		{
			temp ^= v[j];

			if (temp > ans)
				ans = temp;
		}
	}

	std::cout << ans;

	return 0;
}
