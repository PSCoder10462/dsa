#include <iostream>
#include <utility>
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;

  std::cin >> n;

  std::vector<std::pair<int, int>> v(n);

  for (int i = 0; i < n; ++i)
  {
    std::cin >> v[i].first >> v[i].second;
  }

  int ctr = 0;

  for (int i = 0; i < n; ++i)
  {

    bool l, r, u, d;
    l = r = u = d = false;

    for (int j = 0; j < n; ++j)
    {
      if (v[i].first == v[j].first && v[i].second > v[j].second)
        u = true;
      if (v[i].first == v[j].first && v[i].second < v[j].second)
        d = true;
      if (v[i].first > v[j].first && v[i].second == v[j].second)
        l = true;
      if (v[i].first < v[j].first && v[i].second == v[j].second)
        r = true;

      if (l && r && u && d)
      {
        ctr++;
        break;
      }
    }
  }

  std::cout << ctr;

  return 0;
}
