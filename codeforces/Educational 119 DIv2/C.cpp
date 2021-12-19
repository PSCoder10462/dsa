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

void solve() {
    // taking input

    int n, k; ll x; 
    cin >> n >> k >> x;

    string s; cin >> s;


    // run length encoding

    vector<pair<char, int>> v;

    char pr = s[0];
    int cnt = 0;

    for (char c: s) {
        if (c == pr)
            cnt++;
        else {
            v.pb(mp(pr, cnt));
            cnt = 1;
            pr = c;
        }
    }
    v.pb(mp(pr, cnt));

    // convert x-1 to mix base 
    x--;

    vector<int> bases;

    for (auto i: v) {
        if (i.ff == '*')
            bases.pb(i.ss*k+1);
    }

    vector<int> b;

    while (!bases.empty()) {
        b.pb(x%bases.back());
        x /= bases.back();
        bases.pop_back();
    }

    string ans;
    for (auto [ch, cn]: v) {
        if (ch == 'a') 
            ans += string(cn, ch);
        else {
            ans += string(b.back(), 'b');
            b.pop_back();
        }
    }

    cout << ans << endl;
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
