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
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int m;
	std::cin >> m;
	std::vector<int> b(m);
	for (int i = 0; i < m; ++i)
		std::cin >> b[i];

	std::vector<int> ctr;

	for (int i = 0; i < n; ++i)
		for (int j = m - 1; j >= 0; --j)
			if (b[j] % a[i] == 0)
			{
				int g = b[j] / a[i];
				if (g >= ctr.size())
					ctr.resize(g + 1, 0);
				ctr[g]++;
			}

	int s = ctr.size();
	std::cout << ctr[s - 1];

	return 0;
}
