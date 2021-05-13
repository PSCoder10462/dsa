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

	int ans = 1;
	for (int i = 0; i < n; ++i)
	{
		int temp = 1;

		int j = i + 1;

		for (j; j < n; ++j)
		{
			if (v[j] >= v[j - 1])
				temp++;
			else
				break;
		}

		for (j; j < n; ++j)
		{
			if (v[j] <= v[j - 1])
				temp++;
			else
				break;
		}

		if (temp > ans)
			ans = temp;
	}

	std::cout << ans;

	return 0;
}
