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
    vvi v(5, vi (5));
    loop(i, 0, 5)
        loop(j, 0, 5)
            cin >> v[i][j];

    vi p = {0, 1, 2, 3, 4};

    ll ans = ninf;

    do {
        // ab
        ll t = 0;
        t += v[p[0]][p[1]];
        t += v[p[1]][p[0]];

        // bc
        t += v[p[1]][p[2]];
        t += v[p[2]][p[1]];

        // de
        t += 2*v[p[3]][p[4]];
        t += 2*v[p[4]][p[3]];

        // cd
        t += 2*v[p[2]][p[3]];
        t += 2*v[p[3]][p[2]];

        ans = max(ans, t);

    } while (next_permutation(all(p)));

    cout << ans << endl;
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
