/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
// #define mod               1'000'000'007
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

unsigned ll calculate(unsigned ll p, ll q)
{
    unsigned ll mod = 998244353, expo;
    expo = mod - 2;

    // cout << p << ' '; 

    while (expo) {
 
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
 
        expo >>= 1;
    }
    return p;
}

void solve() {
    unsigned ll n; cin >> n;
    n%=998244353;
    unsigned ll a = ((n+1)*(n+1))%998244353;
    a = a*n;
    a %= 998244353;
    cout << calculate(a, 4) << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    while (T--) {
      solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
