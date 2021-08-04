#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vi>
#define vb                vector<bool>
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (int i = a; i <= b; ++i)
#define looprev(i, a, b)  for (int i = a; i >= b; --i)
#define MOD               100'000'007
#define mp                make_pair
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  char c; cin >> c;
  if (c >= 'A' and c <= 'Z') c = char(c + 32);
  switch(c) {
    case 'b': cout << "BattleShip";
      break;
    case 'c': cout << "Cruiser";
      break;
    case 'd': cout << "Destroyer";
      break;
    default: cout << "Frigate";
  }
  cout << endl;
}

int32_t main () {
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
