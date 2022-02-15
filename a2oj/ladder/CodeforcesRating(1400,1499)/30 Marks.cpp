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
    vector<vector<int>> v(n, vector<int>(m));
    loop(i, 0, n) {
        loop(j, 0, m) {
            char c; cin >> c;
            v[i][j] = c-'0';
        }
    }
    set<int> best;
    loop(col, 0, m) {
        int maxx = 0; 
        vector<int> best_stu;
        loop(row, 0, n) {
            if (v[row][col] == maxx) {
                best_stu.pb(row);
            } else if (v[row][col] > maxx) {
                best_stu.clear();
                best_stu.pb(row);
                maxx = v[row][col];
            }
        }
        for (auto &i: best_stu)
            best.insert(i);
    }
    cout << best.size();
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
