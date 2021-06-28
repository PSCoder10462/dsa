#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

vector<string> ans;

void print() {
  for (string s : ans) cout << s << endl;
}

void f(int k, bool p, string osf, int n) {
  if (n == k) {
    ans.push_back(osf);
    return;
  }
  osf.push_back('0');
  f(k, false, osf, n + 1);
  osf.pop_back();
  if (!p) {
    osf.push_back('1');
    f(k, true, osf, n + 1);
    osf.pop_back();
  }
}

void solve() {
  int k;
  cin >> k;
  ans.clear();
  f(k, false, "", 0);
  print();
}

int main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
