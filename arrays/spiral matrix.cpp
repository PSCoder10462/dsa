#define vi vector<int>
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
  vi ans;
  vector<bool> cr(n, false), cc(m, false);
  // Write your code here.
  int u, d, l, r;
  u = l = 0;
  d = n - 1;
  r = m - 1;
  while (u <= d or r >= l) {
    if (u < n and !cr[u]) {
      loop(j, l, r) ans.push_back(matrix[u][j]);
      cr[u] = true;
      u++;
    }
    if (r >= 0 and !cc[r]) {
      loop(j, u, d) ans.push_back(matrix[j][r]);
      cc[r] = true;
      r--;
    }
    if (d >= 0 and !cr[d]) {
      looprev(j, r, l) ans.push_back(matrix[d][j]);
      cr[d] = true;
      d--;
    }
    if (l < m and !cc[l]) {
    looprev(j, d, u) ans.push_back(matrix[j][l]);
      cc[l] = true;
      l++;
    }
  }
  return ans;
}
