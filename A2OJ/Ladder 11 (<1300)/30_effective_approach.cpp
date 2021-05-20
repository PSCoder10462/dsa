#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  int m;
  std::cin >> m;
  std::vector<int> q(m);
  for (int i = 0; i < m; ++i)
    std::cin >> q[i];

  std::unordered_map<int, int> ind;
  for (int i = 0; i < n; ++i)
  {
    ind[v[i]] = i + 1;
  }

  long long V, P;
  V = P = 0;

  for (int i = 0; i < m; ++i)
  {
    if (ind[q[i]])
    {
      V += (ind[q[i]]);
      P += (n + 1 - ind[q[i]]);
    }
    else
    {
      V += n;
      P += n;
    }
  }

  std::cout << V << ' ' << P;

  return 0;
}
