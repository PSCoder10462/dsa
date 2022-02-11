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

const string yes = "YES", no = "NO";

void solve() {
    string a, b; cin >> a >> b;
    int len_a = (int)a.length();
    int len_b = (int)b.length();
    if (len_a != len_b) {
        cout << no; return;
    }
    bool one_a, one_b;
    one_a = one_b = false;
    for(auto i: a) {
        if (i == '1') {
            one_a = true; break;
        }
    }
    for(auto i: b) {
        if (i == '1') {
            one_b = true; break;
        }
    }
    if ((one_a and !one_b) or (one_b and !one_a)) {
        cout << no; return;
    }
    cout << yes;
}

int main () {
    clock_t start = clock();
    file_i_o();
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
