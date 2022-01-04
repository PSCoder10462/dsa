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
    vi v {4, 7};
    ll start = 0;
    ll t = 10;
    loop(i, 1, 10) {
        int n = (int)v.size();
        loop(j, start, n) 
            v.pb(v[j]+4*t);
        loop(j, start, n) 
            v.pb(v[j]+7*t);
        t *= 10;
        start = n;
    }
    v.pb(44444444444);
    
    ll l, r; cin >> l >> r;

    t = 0;

    for (auto i: v) {
        if (i < l) continue;
        if (!t) t += i;
        t += (i * (min(r, i)-l));
        l = i;
        // cout << l << ": " << t << endl;
        if (l >= r) break;
    }

    cout << t;
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
