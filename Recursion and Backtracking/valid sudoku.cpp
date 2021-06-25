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

void print(vvi &s) {
  for (vi i : s) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

bool safe(vvi &s) {
  for (int i = 1; i <= 7; i += 3) {
    for (int j = 1; j <= 7; j += 3) {
      unordered_set<int> f;  // freq
      vi temp{-1, 0, 1};
      for (int x : temp)
        for (int y : temp) {
          int z = s[i + x][j + y];
          if (z != 0) {
            if (f.find(z) == f.end())
              f.insert(z);
            else
              return false;
          }
        }
    }
  }

  loop(i, 0, 8) {
    unordered_set<int> fr, fc;
    loop(j, 0, 8) {
      int z1 = s[i][j], z2 = s[j][i];
      if ((z1 != 0 and fr.find(z1) != fr.end()) or
          (z2 != 0 and fc.find(z2) != fc.end()))
        return false;
      fr.insert(z1);
      fc.insert(z2);
    }
  }

  return true;
}

bool valid(vvi &s, int r, int c) {
  // cout << "Call for: " << r << " " << c << endl;
  // print(s);
  // cout << endl;

  // placed all
  if (r > 8) return true;

  // placed row
  if (c > 8) return valid(s, r + 1, 0);

  // already occupied
  if (s[r][c] != 0) return valid(s, r, c + 1);

  loop(i, 1, 9) {
    // place
    s[r][c] = i;

    // print(s);
    // cout << endl;

    // move
    if (safe(s) and valid(s, r, c + 1)) return true;

    // un-place
    s[r][c] = 0;
  }

  // couldn't place a number
  return false;
}

bool isItSudoku(vvi &s) { return valid(s, 0, 0); }

void solve() {
  vvi sudoku(9);
  loop(i, 0, 8) {
    sudoku[i].resize(9, 0);
    loop(j, 0, 8) cin >> sudoku[i][j];
  }
  isItSudoku(sudoku) ? cout << "true" : cout << "false";
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
