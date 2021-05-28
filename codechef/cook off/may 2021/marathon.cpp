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
    int D, d, a, b, c;
    std::cin >> D >> d >> a >> b >> c;
    int x = d * D;
    if (x >= 42)
      std::cout << c;
    else if (x >= 21)
      std::cout << b;
    else if (x >= 10)
      std::cout << a;
    else
      std::cout << 0;
    std::cout << '\n';
  }

  return 0;
}
