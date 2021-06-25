#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) (l + h / 2)
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

vector<string> ans;

void print(vector<string> a) {
  for (string i : a) {
    cout << i << " ";
  }
  cout << endl;
}

void getPath(vvi &maze, int r, int c, int n, string osf) {
  if (r < 0 or c < 0 or r >= n or c >= n or !maze[r][c]) return;

  if (r == n - 1 and c == n - 1) {
    ans.push_back(osf);
    return;
  }

  maze[r][c] = 0;

  osf.push_back('D');
  getPath(maze, r + 1, c, n, osf);
  osf.pop_back();
  osf.push_back('U');
  getPath(maze, r - 1, c, n, osf);
  osf.pop_back();
  osf.push_back('R');
  getPath(maze, r, c + 1, n, osf);
  osf.pop_back();
  osf.push_back('L');
  getPath(maze, r, c - 1, n, osf);
  osf.pop_back();
  maze[r][c] = 1;
}

vector<string> findAllPaths(vvi &maze) {
  ans.clear();
  int n = maze.size();
  getPath(maze, 0, 0, n, "");
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vvi maze(n, vi(n));
  loop(i, 0, n - 1) loop(j, 0, n - 1) cin >> maze[i][j];
  vector<string> a = findAllPaths(maze);
  print(a);
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
