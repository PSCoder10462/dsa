#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  std::cin >> n;
  int lo = 0, ro = 0;

  for (int i = 0; i < n; ++i)
  {
    int l, r;
    std::cin >> l >> r;
    if (l)
      lo++;
    if (r)
      ro++;
  }

  int ans = 0;

  if (lo > n / 2)
    ans += (n - lo);
  else
    ans += lo;
  if (ro > n / 2)
    ans += (n - ro);
  else
    ans += ro;

  std::cout << ans;

  return 0;
}
