#include <iostream>

int main()
{
  int n;
  std::cin >> n;

  int s = 0;
  for (int i = 0; i < n; ++i)
  {
    int t;
    std::cin >> t;
    s += t;
  }

  std::cout << (double)s / (double)n;

  return 0;
}
