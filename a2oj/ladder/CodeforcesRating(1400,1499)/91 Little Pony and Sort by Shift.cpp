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

bool check_sort(vector<int> &v, int st, int en) {
    loop(i, st+1, en) {
        if (v[i] < v[i-1]) 
            return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int maxx = -1;
    int pos = 0;
    loop(i, 0, n) {
        cin >> a[i];
        if (maxx < a[i]) {
            pos = i;
            maxx = a[i];
        }
    }
    int pos2 = pos;
    while (pos2 < n-1 and a[pos] == a[pos2 + 1]) pos2++;
    bool flag = check_sort(a, 0, pos+1) and check_sort(a, pos2+1, n);
    
    if (!flag) {
        cout << -1; return;
    }
    if (pos != n-1 and a.front() < a.back()) {
        cout << -1; return;
    }
    cout << n-pos2-1;
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
