#include <iostream>
#include <string>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int l, c;
	l = c = 0;
	std::string s, lo, ca;

	std::cin >> s;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			l++;
			lo.push_back(s[i]);
			ca.push_back(s[i] - 32);
		}
		else
		{
			c++;
			ca.push_back(s[i]);
			lo.push_back(s[i] + 32);
		}
	}

	l >= c ? std::cout << lo : std::cout << ca;

	return 0;
}
