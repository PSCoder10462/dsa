#include <iostream>
#include <string>

int main()
{
  std::string a, b;
  std::cin >> a >> b;
  for (int i = 0; i < a.length(); ++i)
    a[i] == b[i] ? std::cout << 0 : std::cout << 1;

  return 0;
}
