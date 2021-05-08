#include <iostream>

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	std::cin >> T;
	while (T--)
	{
		char arr[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				std::cin >> arr[i][j];

		int X, O;
		X = O = 0;
		int x, o;
		x = o = 0;
		int d1, d2;
		d1 = d2 = 0;
		for (int i = 0; i < 3; ++i)
		{
			int r, c;
			r = c = 0;
			for (int j = 0; j < 3; ++j)
			{
				if (arr[i][j] == 'X')
				{
					r++;
					x++;
				}
				if (arr[i][j] == 'O')
				{
					o++;
					r--;
				}
				if (arr[j][i] == 'X')
					c++;
				if (arr[j][i] == 'O')
					c--;
			}

			if (arr[i][2 - i] == 'X')
				d2++;
			if (arr[i][2 - i] == 'O')
				d2--;

			if (arr[i][i] == 'X')
				d1++;
			if (arr[i][i] == 'O')
				d1--;

			if (r == 3)
				X++;
			if (r == -3)
				O++;
			if (c == 3)
				X++;
			if (c == -3)
				O++;
		}

		if (d1 == 3)
			X++;
		if (d1 == -3)
			O++;
		if (d2 == 3)
			X++;
		if (d2 == -3)
			O++;

		// std::cout << "X: " << X << " O: " << O << " x: " << x << " o: " << o << '\n';

		// draw
		if (X == 0 && O == 0 && x == 5 && o == 4)
		{
			std::cout << 1 << '\n';
			continue;
		}

		// no winner but reachable
		if (X == 0 && O == 0 && x - o <= 1 && x - o >= 0 && x + o < 9)
		{
			std::cout << 2 << '\n';
			continue;
		}

		// winner and reachable
		if ((X >= 1 && O == 0 && x - o == 1) || (O == 1 && X == 0 && x == o))
		{
			std::cout << 1 << '\n';
			continue;
		}

		std::cout << 3 << '\n';
	}

	return 0;
}
