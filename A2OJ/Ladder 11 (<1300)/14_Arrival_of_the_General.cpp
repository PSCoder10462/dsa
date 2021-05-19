#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> h(n);

  int lo = 200, hi = 0;
  int lp, hp;

  for (int i = 0; i < n; ++i)
  {
    std::cin >> h[i];
    if (lo >= h[i])
    {
      lp = i;
      lo = h[i];
    }
    if (hi < h[i])
    {
      hp = i;
      hi = h[i];
    }
  }

  int ans = 0;

  if (hp > lp)
    lp++;

  ans += hp;

  ans += (n - lp - 1);

  std::cout << ans;

  return 0;
}
