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

ll get_digit(ll &n) {
    ll ans = n%10;
    n/=10; return ans;
}

void solve() {
    ll a, s; cin >> a >> s;
    ll mult = 1, b = 0;
    while (a or s) {
        ll a_digit = get_digit(a);
        ll s_digit = get_digit(s);
        if (a_digit > s_digit)
            s_digit += 10*get_digit(s);
        if (a_digit > s_digit or s_digit > 18) {
            cout << -1 << endl; return;
        }
        b += (s_digit - a_digit)*mult;
        mult *= 10;
    }
    cout << b << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    int tt; cin >> tt;
    while (tt--)
        solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
