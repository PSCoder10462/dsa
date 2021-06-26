// optimized for T <= 10 and N <= 10

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define loop(i, a, b) for (int i = a; i <= b; ++i)

// first and second diagonal
vi fd, sd, column;

bool first = true;

map<int, vvi> mp;

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

void func() {
  loop(i, 1, 10) {
      vi board(i * i);
      fd.clear();
      fd.resize(2 * i, 0);
      sd.clear();
      sd.resize(2 * i, 0);
      column.clear();
      column.resize(2 * i, 0);
      vvi ans;
      f(i, 0, board, ans);
      mp.insert(std::make_pair(i, ans));
  }
  first = false;
}

vvi nQueens(int n) {
  if (first) func();
  return mp[n];
}
