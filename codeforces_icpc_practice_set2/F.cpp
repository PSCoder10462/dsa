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

	int min, cnt = 1, pos = 0;
	min = v[0];
	for (int i = 1; i < n; ++i)
	{
		if (min == v[i])
		{
			cnt++;
		}
		if (v[i] < min)
		{
			min = v[i];
			cnt = 1;
			pos = i;
		}
	}

	if (cnt == 1)
		std::cout << pos + 1;
	else
		std::cout << "Still Rozdil";

	return 0;
}
