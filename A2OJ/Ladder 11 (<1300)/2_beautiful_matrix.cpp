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
	vvi v(5, vi(5));
	int r, c;
	r = c = 0;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			std::cin >> v[i][j];
			if (v[i][j])
			{
				r = i + 1;
				c = j + 1;
			}
		}

	int ans = 0;
	ans += (abs(r - 3) + abs(c - 3));

	std::cout << ans;
	return 0;
}
