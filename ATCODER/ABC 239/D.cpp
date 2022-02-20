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

bool is_prime(int n) {
    for (int i=2; i*i <= n; ++i)
        if (n%i == 0) 
            return false;
    return true;
}

void solve() {
    pair<int, int> t, a;
    cin >> t.ff >> t.ss >> a.ff >> a.ss;
    bool tak = false;
    loop(i, t.ff, t.ss+1) {
        bool aoki = false;
        loop(j, a.ff, a.ss+1) {
            if (is_prime(i+j)) {
                // cout << i + j << endl;
                aoki = true;
                break;
            }
        }
        if (!aoki) {
            tak = true; break;
        }
    }
    cout << (tak ? "Takahashi": "Aoki");
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
