#include <iostream>
#include <unordered_map>
#define int long long

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	std::cin >> n;

	std::unordered_map<int, int> m;

	int hi = -100000, lo = 100000;

	for (int i = 0; i < n; ++i)
	{
		int x, d;
		std::cin >> x >> d;
		if (x > hi)
			hi = x;
		if (x < lo)
			lo = x;
		m[x] = d;
	}

	for (int i = lo; i < hi; ++i)
	{
		if (!m[i])
			continue;

		int spit_at = m[i] + i;

		if (!m[spit_at])
			continue;

		int spit_from = m[spit_at] + spit_at;

		if (i == spit_from)
		{
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";

	return 0;
}
