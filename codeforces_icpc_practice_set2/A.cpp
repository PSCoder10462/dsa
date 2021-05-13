#include <iostream>
#include <vector>
#include <algorithm>

int main()
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

	std::sort(v.begin(), v.end());

	bool found = false;
	int a1 = v[0], ans;

	for (auto x : v)
	{
		if (a1 == x)
			continue;
		else
		{
			std::cout << x;
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "NO";

	return 0;
}
