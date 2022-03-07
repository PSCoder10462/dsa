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
    ll n, k; cin >> k;
    string s; cin >> s;
    n = (ll)s.length();
    ll en, st;
    ll ans = 0;
    en = 0;
    st = -1;
    if (k == 0) {
        while (en < n) {
            while (en < n and s[en] != '1') {
                en++;    
            }   
            ll t = en-st-1;
            ans += t*(t+1)/2;
            st = en;
            en++;
        }
        cout << ans; return;
    }
    
    vector<ll> prev, next(n);
    ll z = 0;
    loop(i, 0, n) {
        prev.pb(z);
        z++;
        if (s[i] == '1') z = 0;
    }
    z = 0;
    looprev(i, n-1, 0) {
        next[i] = z;
        z++;
        if (s[i] == '1') z = 0;
    }
    
    ll cnt = 0;
    while (en < n) {
        while (cnt < k and en < n) {
            if (s[en] == '1') cnt++;
            en++;
        } 
        while (cnt == k) {
            if (s[st] == '1') break;
            st++;
        }
        if (cnt == k) {
            ans += (next[en-1]+1)*(prev[st]+1);
        }
        st++;
        cnt--;
    }
    cout << ans << endl;
    
    // debug...
    // for (auto const &i: prev) cout << i << ' ';
    // cout << endl;
    // for (auto const &i: next) cout << i << ' ';
    
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
