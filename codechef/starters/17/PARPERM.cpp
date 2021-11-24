/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
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

ll lim = (ll)1e5;

vector<bool> primes(lim+5, true);

void init_primes() {
    loop(i, 2, lim+2) {
        if (!primes[i]) continue;
        for (ll j=2; j*i < lim+2; j++) 
            primes[i*j] = false;
    }
}

void solve() {
    ll n, k; cin >> n >> k;
    ll temp = k;
    unordered_set<ll> f = {1};
    loop(i, n/2+1, n)  if (primes[i]) f.insert(i);
    ll m = f.size();

    vi ans;

    if (n-m <= k) {
        loop(i, 1, n) {
            if (f.find(i) != f.end()) continue;
            ans.pb(i);
        }
        k -= (n-m);
    }
   
    if (m+1 >= k) {
        for (auto i=f.begin(); k and i!=f.end(); ++i) {
            ans.pb(*i); --k;
            if (!k) {break;}
        }
    } 

    if ((ll)ans.size() == temp) {
        cout << "YES" << endl;
        for (auto const &i: ans) cout << i << ' ';
        cout << endl; 
        return; 
    }

    cout << "NO" << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    init_primes();
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
