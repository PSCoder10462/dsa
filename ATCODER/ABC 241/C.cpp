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

int n;

bool check (int r, int c, vector<vector<char>> &m) {
    if (r <= n-6) {
        int b = 0;
        loop(i, r, r+6) {
            b += (m[i][c] == '#');
        }
        if (b >= 4) {
            return true;
        }
    }
    if (c <= n-6) {
        int b = 0;
        loop(i, c, c+6) {
            b += (m[r][i] == '#');
        }
        if (b >= 4) {
            return true;
        }
    }
    if (c <= n-6 and r <= n-6) {
        int b = 0;
        loop(i, 0, 6) {
            b += (m[r+i][c+i] == '#');
        }
        if (b >= 4) {
            return true;
        }
    }
    if (c >= 5 and r <= n-6) {
        int b = 0;
        loop(i, 0, 6) {
            b += (m[r+i][c-i] == '#');
        }
        if (b >= 4) {
            return true;
        }
    }
    return false;
}
 
void solve() {
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    loop(i, 0, n) {
        loop(j, 0, n) {
            cin >> m[i][j];
        }
    }
    loop(i, 0, n) {
        loop(j, 0, n) {
            if (check(i, j, m)) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
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
