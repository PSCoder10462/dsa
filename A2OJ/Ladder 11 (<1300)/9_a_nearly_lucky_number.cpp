#include <iostream>

bool check(int n)
{
  if (!n)
    return false;

  while (n)
  {
    int x = n % 10;
    if (x != 4 && x != 7)
      return false;
    n /= 10;
  }

  return true;
}

int main()
{
  unsigned long long n;
  std::cin >> n;
  int ctr = 0;

  while (n)
  {
    int x = n % 10;
    if (x == 4 || x == 7)
      ctr++;
    n /= 10;
  }

  check(ctr) ? std::cout << "YES" : std::cout << "NO";

  return 0;
}
