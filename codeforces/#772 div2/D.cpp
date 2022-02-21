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
    ll n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    sort(all(v));
    vector<int> dp(p);
    // dp[i] = number of elements with value >= 2^i
    
    // only keeping non redundant data
    set<int> useful;
    for (auto i: v) {
        // i can be produced if 
        // i/2 is present in array
        int x = i;
        bool flag = false;
        // flag -> true => don't add
        // flag -> false => add;
        while (x) {
            // if x is already there, don't add
            if (useful.count(x))
                flag = true;
            
            if (x&1) {
                // odd x can be acheived only via 2x+1
                x >>= 1;
            } else if (x&2) {
                // can't make this via given any operation
                break;
            } else {
                // may be made by 4x
                x >>= 2;
            }
        }    
        if (!flag) 
            useful.insert(i);
    }
    
    vector<int> arr(32, 0);
    
    for (auto i: useful) {
        int msb = __lg(i);
        arr[msb]++;
    }
    
    int ans = 0;

    loop(i, 0, p) {
        dp[i] = (i<32 ? arr[i] : 0);
        dp[i] += (i>0 ? dp[i-1] : 0);
        dp[i] %= mod;
        dp[i] += (i>1 ? dp[i-2]: 0);    
        dp[i] %= mod;
        ans += dp[i];
        ans %= mod;
    }
    
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
