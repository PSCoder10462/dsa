#include <bits/stdc++.h>

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  std::cin >> n >> m;
  std::queue<std::pair<int, int>> q;

  for (int i = 0; i < n; ++i)
  {
    int t;
    std::cin >> t;
    q.push(std::make_pair(t, i + 1));
  }

  while (!q.empty())
  {
    std::pair<int, int> x = q.front();
    q.pop();
    if (x.first > m)
    {
      q.push(std::make_pair(x.first - m, x.second));
    }
    if (q.empty())
      std::cout << x.second;
  }

  return 0;
}
