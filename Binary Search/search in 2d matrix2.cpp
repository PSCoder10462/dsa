#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) ((l + h) / 2)

bool findInMatrix(int x, vector<vector<int>> &arr) {
  int n, m, k;
  n = arr.size();
  m = arr[0].size();
  k = x;

  for (int i = 0; i < n; ++i) {
    if (arr[i][0] <= k and arr[i][m - 1] >= k) {
      int pc = lower_bound(arr[i].begin(), arr[i].end(), k) - arr[i].begin();
      if (pc >= 0 and pc < m) {
        if (arr[i][pc] == k) return true;
      }
    }
  }

  return false;
}
