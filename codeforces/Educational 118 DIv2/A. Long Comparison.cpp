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

ll nod(ll n) {
    ll nod = 0;
    while (n) {
        n/=10; nod++;
    }
    return nod;
}

void solve() {
    ll x, y, px, py; cin >> x >> px >> y >> py;
    ll nx = nod(x), ny = nod(y);
    if (nx  + px > ny + py) {
        cout << ">\n"; return;
    } 
    if (nx  + px < ny + py) {
        cout << "<\n"; return;
    }
    while (nx < ny) {x*=10; nx++;}
    while (nx > ny) {y*=10; ny++;}
    if (x == y) {cout << "=\n"; return;}
    cout << (x > y ? '>' : '<') << endl;
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