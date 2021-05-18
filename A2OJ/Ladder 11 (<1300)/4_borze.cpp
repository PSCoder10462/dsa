#include <iostream>
#include <string>
#define bg "BG"
#define zero "."
#define one "-."
#define two "--"

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::string s;
	std::cin >> s;
	int n = s.length();
	int i = 0;
	while (i < n)
	{
		std::string check = s.substr(i, 2);
		if (check == two)
		{
			std::cout << '2';
			i += 2;
		}
		else if (check == one)
		{
			std::cout << '1';
			i += 2;
		}
		else
		{
			std::cout << '0';
			i++;
		}
	}
	return 0;
}
