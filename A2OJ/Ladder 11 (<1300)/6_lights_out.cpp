#include <iostream>
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::vector<std::vector<int>> v(5, std::vector<int>(5));
	std::vector<std::vector<int>> ans(5, std::vector<int>(5));

	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			std::cin >> v[i][j];

	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
		{
			ans[i][j] +=
					(v[i - 1][j] +
					 v[i][j - 1] + v[i][j] + v[i][j + 1] +
					 v[i + 1][j]);
		}

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
			ans[i][j] % 2 ? std::cout << "0" : std::cout << "1";
		std::cout << '\n';
	}

	return 0;
}
