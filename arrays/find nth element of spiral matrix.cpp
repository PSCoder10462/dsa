#define vi vector<int>
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)

int findKthElement(vector<vector<int>> matrix, int k) {
    // Write your code here.
    int n = matrix.size(), m = matrix[0].size();
  int ans = 0;
  vector<bool> cr(n, false), cc(m, false);
  // Write your code here.
  int u, d, l, r;
  u = l = 0;
  d = n - 1;
  r = m - 1;
  while (u <= d or r >= l) {
    if (u < n and !cr[u]) {
      loop(j, l, r) {
        ans++;
        if (ans == k)
          return matrix[u][j];
      }
      cr[u] = true;
      u++;
    }
    if (r >= 0 and !cc[r]) {
      loop(j, u, d) {
        ans++;
        if (ans == k)
          return matrix[j][r];
      }
      cc[r] = true;
      r--;
    }
    if (d >= 0 and !cr[d]) {
      looprev(j, r, l) {
        ans++;
        if (ans == k)
          return matrix[d][j];
      }
      cr[d] = true;
      d--;
    }
    if (l < m and !cc[l]) {
    looprev(j, d, u) {
        ans++;
        if (ans == k)
          return matrix[j][l];
      }
      cc[l] = true;
      l++;
    }
  }
  return ans;
}
