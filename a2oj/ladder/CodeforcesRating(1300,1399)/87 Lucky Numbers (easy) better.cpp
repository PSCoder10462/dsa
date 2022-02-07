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

vi super_lucky;

void gen_nums(int four, int seven, ll num) {
    if (!four and !seven) {
        super_lucky.pb(num);
        return;
    }
    if (!four) {
        num *= 10;
        num += 7;
        gen_nums(four, seven-1, num);
    }
    else if (!seven) {
        num *= 10;
        num += 4;
        gen_nums(four-1, seven, num);
    }
    else {
        num *= 10;
        num += 4;
        gen_nums(four-1, seven, num);
        num/=10;
        num *= 10;
        num += 7;
        gen_nums(four, seven-1, num);
    }
}

void solve() {
    loop(i, 1, 6) {
        gen_nums(i, i, 0);
    }
    sort(all(super_lucky));
    ll n; cin >> n;
    ll pos = lower_bound(all(super_lucky), n) - super_lucky.begin();
    cout << super_lucky[pos];
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
