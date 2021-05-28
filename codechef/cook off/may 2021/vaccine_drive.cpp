#include <bits/stdc++.h>

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
    int amin, amax;
    int g, p;
    std::vector<int> v(10);
    std::cin >> g >> p;
    for (int i = 0; i < 10; ++i)
      std::cin >> v[i];

    int bmin, bmax;
    bmin = 0;

    for (int i = g; i < 10; ++i)
      bmin += v[i];

    bmax = bmin + v[g - 1];
    bmin++;

    amin = ceil((float)bmin / p);
    amax = ceil((float)bmax / p);

    std::cout << amin << ' ' << amax << '\n';
  }

  return 0;
}
