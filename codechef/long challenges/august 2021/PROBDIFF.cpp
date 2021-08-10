#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (ll i = a; i <= b; ++i)
#define looprev(i, a, b)  for (ll i = a; i >= b; --i)
#define mod               1'000'000'007
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
  set<int> st;
  v<int> f(11, 0);
  loop(i, 1, 4) {
    int n; cin >> n;
    f[n]++;
    st.insert(n);
  }
  int n = (int)st.size();
  switch(n) {
    case 4: cout << 2; break;
    case 3: cout << 2; break;
    case 2: {
        bool twice = false;
        for (int i: f) {
            if (i == 2) {
                twice = true; break;
            }
            if (i == 3) {
                twice = false; break;
            }
        }
        twice ? cout << 2 : cout << 1;
        break;
    }
    case 1: cout << 0; break;
  }
  cout << endl;
}

int main () {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T;
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
