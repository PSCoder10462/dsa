#include <iostream>
#include <set>

bool check(int n)
{
	std::set<int> s;
	while (n)
	{
		int x = n % 10;
		if (s.find(x) != s.end())
			return false;
		s.insert(x);
		n /= 10;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, ans = 0;
	std::cin >> n;

	int i = n + 1;
	for (i; !check(i); ++i)
		;

	std::cout << i;

	return 0;
}
