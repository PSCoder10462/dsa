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
    int n; cin >> n;
    vector<bool> v(n);
    loop(i, 0, n) {
        int t; cin >> t;
        v[i] = t;
    }

    int temp, ans, st, en, tst;
    temp = ans = st = en = tst = 0;

    loop(i, 0, n) {
        if (v[i]) temp--;
        else temp++;

        if (temp < 0) {
            temp = 0;
            tst = i+1;
        }

        if (temp > ans) {
            ans = temp;
            st = tst;
            en = i;
        }
    }

    ans += (en-st+1 - ans)/2;

    loop(i, 0, st) ans += (v[i] ? 1 : 0);
    loop(i, en+1, n) ans += (v[i] ? 1 : 0);

    cout << ans;

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
