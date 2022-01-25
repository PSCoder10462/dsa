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
    ll n; cin >> n;
    vector<pii> t; // last occ, cd
    unordered_set<ll> rej;
    loop(i, 0, n) {
        ll a; cin >> a;

        if (rej.find(a) != rej.end()) continue;

        // first occ

        if ((ll)t.size() <= a) {
            t.resize(a+1, mp(-1, 0));
            t[a].ff = i;
            continue;
        }

        if (t[a].ff == -1) {
            t[a].ff = i;
            continue;
        } 

        // second occ

        if (t[a].ff != -1 and t[a].ss == 0) {
            t[a].ss = i - t[a].ff;
            t[a].ff = i;
            continue;
        }


        // n-th occ
        if (i-t[a].ff != t[a].ss) {
            rej.insert(a); continue;
        }

        t[a].ff = i;
    }

    ll z = (ll)t.size();

    vector<pii> ans;

    loop(i, 1, z) {
        if (rej.find(i) != rej.end() or t[i].ff == -1) continue;
        ans.pb(mp(i, t[i].ss));
    }

    cout << ans.size() << endl;
    for (auto [a, b]: ans) 
        cout << a << ' ' << b << endl;
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
