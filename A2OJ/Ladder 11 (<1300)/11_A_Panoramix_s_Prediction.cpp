#include <iostream>

bool checkPrime(int n)
{
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  int x = n + 1;

  while (!checkPrime(x))
    x++;

  x == m ? std::cout << "YES" : std::cout << "NO";

  return 0;
}
