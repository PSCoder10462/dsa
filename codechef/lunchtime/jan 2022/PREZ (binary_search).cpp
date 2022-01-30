// TC: O(NlogN) : verdict -> Accepted
/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool poss (const string &s, ll m, ll k) {
    ll ctr = 0;
    looprev(i, m, 0) {
        ll v = (s[i]-'0' + ctr)%10;
        if (v and 10-v > k)
            return false;
        k -= ((10-v)%10);
        ctr += (10-v);
        ctr %= 10;
    }
    return true;
}

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll lo = -1, hi = n;
    while (lo != hi - 1) {
        ll m = mid(lo, hi);
        if (poss(s, m, k)) lo = m;
        else hi = m;
    }
    cout << lo+1 << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
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
