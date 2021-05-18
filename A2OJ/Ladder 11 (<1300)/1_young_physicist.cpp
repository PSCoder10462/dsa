#include <iostream>
#include <vector>
#define vi std::vector<int>
#define vvi std::vector<vi>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	std::cin >> n;
	vvi v(n, vi(3));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			std::cin >> v[i][j];

	for (int i = 0; i < 3; ++i)
	{
		int s = 0;
		for (int j = 0; j < n; ++j)
		{
			s += v[j][i];
		}
		if (s != 0)
		{
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}
