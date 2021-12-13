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
    int n, m; cin >> n >> m;
    vi a(m);
    for (auto &i: a) cin >> i;
    sort(all(a));
    vi b;
    looprev(i, m-1, 0) b.pb(a[i]);
    int minc, maxc; 
    minc = maxc = 0;
    ll minn, maxx; 
    minn = maxx = 0;
    loop(i, 0, n) {
        minn += a[minc];
        a[minc]--;
        if (!a[minc]) minc++;
        maxx += b[maxc];
        b[maxc]--;
        if (maxc == m-1) maxc = 0;
        else if (b[maxc+1] > b[maxc]) maxc++;
        else maxc = 0;
    }
    cout << maxx << ' ' << minn;
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
