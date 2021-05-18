#include <iostream>
#include <string>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::string s;
	std::cin >> s;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;

	std::cout << s;

	return 0;
}
