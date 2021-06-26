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

// first and second diagonal
vi fd, sd, column;

void print(vvi &mat) {
  for (vi i : mat) {
    for (int j : i) cout << j << " ";
    cout << endl;
  }
}

bool can_place(int r, int c, int n) {
  // check first, second diagonal and column
  if (fd[r - c + n - 1] != 1 or sd[r + c] != 1 or column[c] != 1) return false;
  // all safe
  return true;
}

void f(int n, int r, vi &board, vvi &ans) {
  // placed all queens
  if (r == n) {
    ans.push_back(board);
    return;
  }

  // handle check if queen is placed in current row
  bool placed = false;

  // place queen in rth row
  loop(i, 0, n - 1) {
    fd[r - i + n - 1]++;
    sd[r + i]++;
    column[i]++;
    if (can_place(r, i, n)) {
      board[r + n * i] = 1;
      f(n, r + 1, board, ans);
      // remove queen
      board[r + n * i] = 0;
      placed = true;
    }
    fd[r - i + n - 1]--;
    sd[r + i]--;
    column[i]--;
  }

  if (not placed) return;
}

vvi nQueens(int n) {
  vi board(n * n);
  fd.clear();
  fd.resize(2 * n, 0);
  sd.clear();
  sd.resize(2 * n, 0);
  column.clear();
  column.resize(2 * n, 0);
  vvi ans;
  f(n, 0, board, ans);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vvi ans = nQueens(n);
  print(ans);
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
