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
    // code goes here
    ll n; cin >> n;
    ll k; cin >> k;
    vector<bool> vis(n, false);
    vector<ll> a(n);
    for (auto &i: a) cin >> i;
    ll cycle_size=0, start = 0;
    ll candies = 0;
    // vi cycle;
    while (!vis[start]) {
        // cycle.pb(candies);
        vis[start] = true;
        candies += a[start];
        start = candies%n;
        cycle_size++;
    }
    ll temp = 0;
    ll i = 0;
    while (i != start) {
        temp += a[i];
        i = temp%n;
        cycle_size--;
        k--;
        if (!k) {
            cout << temp; return;
        }
    }
    candies -= temp;
    temp += (k/cycle_size) * candies;
    
    k %= cycle_size;
    
    while (k > 0) {
        k--;
        temp += a[start];
        start = temp%n;
    }
    cout << temp;
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
