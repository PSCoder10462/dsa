#include <iostream>
#include <vector>
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
		int n, m;
		std::cin >> n >> m;
		int ctr = 0;
		std::vector<int> v(n + 1, 1);
		for (int i = 2; i <= n; ++i)
		{
			int a = m % i;
			ctr += v[a];
			for (int j = a; j <= n; j += i)
			{
				v[j]++;
			}
		}

		std::cout << ctr << '\n';
	}
	return 0;
}
