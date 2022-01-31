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

void min_self(int &a, int b) {
    a = min(a, b);
}

void solve() {
    // code goes here
    int a, b; cin >> a >> b;
    int ops = b - a;
    loop(i, a, b) {
        int nb = 0;
        looprev(j, 21, 0) {
            int t = 1<<j; 
            if (b&t) 
                nb ^= t;
            else {
                if (i&t) {
                    nb ^= t;
                    break;
                }
            }
        }
        int nops = i-a;
        nops += 1;
        nops += (i|nb)-b;
        // cout << nb << ' ';
        min_self(ops, nops);
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
