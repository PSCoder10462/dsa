/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<int, int>
#define pb                push_back
#define sz(container)     (container.size()) 
#define mid(l, h)         (l+(h-l)/2)
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
    unordered_map<int, int> mp;
    vi v;
    loop(i, 0, n) {
        int t; cin >> t;
        mp[t] = i;
        v.pb(t);
    }
    
    vi v1 = v;
    
    sort(all(v1));
    
    int ans = 0, ind = 1e18;
    
    for (auto j: v1) {
        int i = mp[j];
        if (i < ind) ans++;
        ind = i;
    }
    
    mp[0] = -1e18; mp[n+1] = 1e18;
        
    while (m--) {
        int c, d; cin >> c >> d;
        int a = v[c-1], b = v[d-1];
      
        swap(v[c-1], v[d-1]);
        
        if (mp[a] > mp[a+1]) ans--;
        if (mp[a-1] > mp[a]) ans--;
        
        if (b+1 != a and mp[b] > mp[b+1]) ans--;
        if (b-1 != a and mp[b-1] > mp[b]) ans--;
                
        // swapping a, b
        int new_b = mp[a], new_a = mp[b];
        mp[a] = new_a;
        mp[b] = new_b;
                
        if (mp[a] > mp[a+1]) ans++;
        if (mp[a-1] > mp[a]) ans++;
          
        if (b+1 != a and mp[b] > mp[b+1]) ans++;
        if (b-1 != a and mp[b-1] > mp[b]) ans++;
      
        cout << ans << endl;
    }
}

int32_t main () {
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
