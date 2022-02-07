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

ll number_of_digits(ll n) {
    ll digits = 0;
    while (n) {
        ++digits; 
        n/=10;
    }
    return digits;
}

ll get_max(ll n) {
    ll maxx = 0;
    loop(_, 0, n/2) {
        maxx*=10;
        maxx+= 7;
    }
    loop(_, 0, n/2) {
        maxx*=10;
        maxx+= 4;
    }
    return maxx;
}

ll get_min(ll n) {
    ll num = 0;
    loop(_, 0, n/2) {
        num*=10;
        num+= 4;
    }
    loop(_, 0, n/2) {
        num*=10;
        num+= 7;
    }
    return num; 
}

bool super_lucky(ll n) {
    ll four, seven; four = seven = 0;
    while (n) {
        ll r = n%10;
        switch(r) {
            case 4: four++; break;
            case 7: seven++; break;
            default: return false;
        }
        n/=10;
    }
    return four == seven;
}

void solve() {
    ll n; cin >> n;
    ll digits = number_of_digits(n);
    if (digits&1) {
        cout << get_min(digits+1); return;
    }
    ll maxx = get_max(digits);
    if (maxx < n) {
        cout << get_min(digits+2); return;
    }
    ll minn = get_min(digits);
    if (n <= minn) {
        cout << minn; return;
    }
    ll ans = maxx; 
    while (maxx >= n) {
        if (super_lucky(maxx)) 
            ans = maxx;
        maxx--;
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
