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
	std::vector<int> v(n), ans;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
		sum += v[i];
	}

	if (sum % n != 0)
	{
		std::cout << 0;
		return 0;
	}

	int avg = sum / n;

	for (int i = 0; i < n; ++i)
	{
		int x = v[i];
		if (x == avg)
		{
			ans.push_back(i);
		}
	}

	std::cout << ans.size() << "\n";
	for (auto x : ans)
	{
		std::cout << x + 1 << " ";
	}

	return 0;
}
