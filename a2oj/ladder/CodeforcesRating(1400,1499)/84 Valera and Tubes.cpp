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
    int n, m, k; cin >> n >> m >> k;
    int i, j;
    bool rev = false;
    i = j = 1;
    int len = 0;
    vector<vector<int>> ans(k); 
    int cur = 0;
    while (k > 1) {
        if (!len) 
            ans[cur].pb(2);
        ans[cur].pb(i);
        ans[cur].pb(j);
        ++len;
        if (rev and j == 1) {
            i++;
            j--;
            rev = !rev;
        } 
        if (!rev and j == m) {
            i++;
            j++;
            rev = !rev;
        }
        if (len == 2) {
            len = 0;
            cur++;
            --k;
        }
        j = (rev ? j-1 : j+1);
    }
    
    cur = (int)ans.size()-1;
    
    ans[cur].pb(0);
    while (i <= n) {
        ans[cur].pb(i);
        ans[cur].pb(j);
        if (rev and j == 1) {
            i++;
            j--;
            rev = !rev;
        } 
        if (!rev and j == m) {
            i++;
            j++;
            rev = !rev;
        }
        j = (rev ? j-1 : j+1);
        ans[cur][0]++;
    }
    
    for(auto p: ans) {
            for(auto q: p) cout << q << ' ';
            cout << endl;
        }    
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
