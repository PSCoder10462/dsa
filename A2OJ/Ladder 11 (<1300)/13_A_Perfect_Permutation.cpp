#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  if (n % 2 != 0)
  {
    std::cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; i += 2)
    std::cout << i + 1 << " " << i << ' ';
  return 0;
}
