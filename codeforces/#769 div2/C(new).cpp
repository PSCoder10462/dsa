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

void min_self (int &a, int b){
    a = min(a, b);
}

void solve() {
    int a, b; cin >> a >> b;
    int ops = b-a;
    loop(i, a, b) {
        int set_a_unset_b = (((1<<21)-1)^b)&i;
        int frb = 31 - __builtin_clz(set_a_unset_b);
        int nb = 0; 
        if (frb == 0) {
            nb = b;
        } else {
            nb = (b>>(frb+1));
            nb <<= (frb+1);
            nb ^= (1<<frb);
        }
        // cout << frb << ' ';
        int new_ops = i-a + (nb|i) - b + 1;
        min_self(ops, new_ops);
    }
    cout << ops << endl;
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
