#include <iostream>
#include <set>

int main()
{
  std::set<int> s;
  int k, l, m, n, d;
  std::cin >> k >> l >> m >> n >> d;

  for (int i = 1; k * i <= d || l * i <= d || m * i <= d || n * i <= d; ++i)
  {
    if (k * i <= d)
      s.insert(k * i);
    if (l * i <= d)
      s.insert(l * i);
    if (m * i <= d)
      s.insert(m * i);
    if (n * i <= d)
      s.insert(n * i);
  }

  std::cout << s.size();

  return 0;
}
