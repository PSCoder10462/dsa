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
    int n, p; cin >> n >> p;
    p--;
    string s; cin >> s;
    int fir, last;
    fir = last = -1;
    int i=0, j=n-1;
    int ans = 0;
    while (i < j) {
        if (s[i] != s[j]) {
            if (fir == -1) 
                fir = i;
            last = i;
            if (s[i] > s[j])
                swap(s[i], s[j]);
            ans += min(int(s[j]-s[i]), 26 - (s[j]-s[i]));
        }
        if (j == p)
            p = i;
        i++; j--;
    }
    if (fir != -1)
        ans += min(abs(p-fir), abs(p-last)) + last - fir;
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
