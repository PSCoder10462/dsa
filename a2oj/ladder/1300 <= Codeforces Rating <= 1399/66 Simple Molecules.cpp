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

void func(vi &ans, ll a, ll b, ll bond) {
    ll t = max(a, b);
    b = min(a, b);
    a = t;
    switch(b) {
        case 1: if (a == 2)
                    ans[0] += bond;
                else 
                    ans[2] += bond;
            break;
        default: ans[1] += bond;
    }
}

void solve() {
    vector<pii> v(3);
    loop(i, 0, 3) {
        v[i].ss = i+1;
        cin >> v[i].ff;
    }
    sort(all(v));
    ll t = v[0].ff + v[1].ff - v[2].ff;
    if (t < 0 or t % 2 == 1) {
        cout << "Impossible"; return;
    }
    vi ans(3);
    func(ans, v[0].ss, v[1].ss, t/2);
    v[0].ff -= t/2;
    v[1].ff -= t/2;
    func(ans, v[0].ss, v[2].ss, v[0].ff);
    func(ans, v[1].ss, v[2].ss, v[1].ff);
    for (auto const &i: ans) cout << i << ' ';
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
