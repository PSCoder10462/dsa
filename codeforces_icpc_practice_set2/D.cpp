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
	int arr[n][n];
	std::vector<int> row(n), col(n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			std::cin >> arr[i][j];
			row[i] += arr[i][j];
			col[j] += arr[i][j];
		}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (row[i] < col[j])
				ans++;
		}

	std::cout << ans;
	return 0;
}
