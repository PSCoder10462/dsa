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
    ll n, r, avg; cin >> n >> r >> avg;
    vector<pii> v(n); // essays, grade
    ll grade = 0;
    for (auto &i: v) { 
        cin >> i.ss >> i.ff;
        grade += i.ss;
    }
    sort(all(v));
    ll essays = 0;
    ll ex = 0;
    ll req = avg*n;
    // for (auto const &i: v) cout << i.ff << ' ' << i.ss << endl;
    while (grade < req) {
        while (v[ex].ss >= r) ex++;
        ll max_grade = grade + r-v[ex].ss;;
        if (max_grade >= req) {
            // can complete
            essays += (req-grade)*v[ex].ff;
            break;
        } else {
            // can't complete
            grade = max_grade;
            essays += (r-v[ex].ss)*v[ex].ff;
        }
        ex++;
    }
    cout << essays;
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
