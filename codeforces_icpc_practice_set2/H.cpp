#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

bool possible(std::vector<int> &a, int ts, int left, int p)
{
	int n = 6;

	if (ts == 0 && left == 0)
		return true;

	if ((left == 0 && ts != 0) || ts < 0)
		return false;

	if (p == n)
		return false;

	return possible(a, ts - a[p], left - 1, p + 1) || possible(a, ts, left, p + 1);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::vector<int> a;

	int sum = 0;
	for (int i = 0; i < 6; ++i)
	{
		int t;
		std::cin >> t;
		a.push_back(t);
		sum += t;
	}

	if (sum % 2 != 0)
		std::cout << "NO";
	else
		possible(a, sum / 2, 3, 0) ? std::cout << "YES" : std::cout << "NO";

	return 0;
}
