#include <bits/stdc++.h>

int bscol(vector<vector<int>> &m, int x) {
  int lo = 0, hi = m.size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (mid == m.size() - 1 or (m[mid][0] <= x and m[mid + 1][0] > x))
      return mid;
    if (m[mid][0] > x)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return -1;
}

pair<int, int> search(vector<vector<int>> matrix, int x) {
  // Write your code here.
  pair<int, int> ans;
  int i = bscol(matrix, x);
  if (i == -1) {
    ans.first = -1;
    ans.second = -1;
    return ans;
  }

  int lo = 0, hi = matrix.size();
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (matrix[i][mid] == x) {
      ans.first = i;
      ans.second = mid;
      return ans;
    }
    if (matrix[i][mid] > x)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  ans.first = -1;
  ans.second = -1;
  return ans;
}
