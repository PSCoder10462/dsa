#include <iostream>
#include <string>
#define bg "BG"

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, t;
	std::cin >> n >> t;
	std::string s;
	std::cin >> s;

	for (int j = 0; j < t; ++j)
	{
		for (int i = 0; i < s.length() - 1; i++)
		{
			std::string temp;
			temp.push_back(s[i]);
			temp.push_back(s[i + 1]);

			if (temp == bg)
			{
				s[i] = 'G';
				s[i + 1] = 'B';
				++i;
			}
		}
	}
	std::cout << s;

	return 0;
}
