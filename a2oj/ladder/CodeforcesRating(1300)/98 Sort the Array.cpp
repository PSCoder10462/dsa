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
    vi a(n), b(n);
    loop(i, 0, n) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));

    ll ind = 0;

    while (ind < n-1 and a[ind] <= a[ind+1]) ind++;

    ll st = ind;

    while (ind < n-1 and a[ind] >= a[ind+1]) ind++;

    ll en = ind;

    reverse(a.begin()+st, a.begin()+en+1);

    loop(i, 0, n) {
        if (a[i] != b[i]) {
            cout << "no"; return;
        }
    }

    cout << "yes\n" << st+1 << ' ' << en+1;

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
