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

void heapify(vi &arr, int i, int n) {
    int left = i*2 + 1;
    int right = i*2 + 2;

    int largest = i;
    if (left < n and arr[left] > arr[largest])
        largest = left;
    if (right < n and arr[right] > arr[largest])
        largest = right;
    if (largest == i) return;
    swap(arr[i], arr[largest]);
    heapify(arr, largest, n);
}

void heapPop(vi &arr, int n) {
    swap(arr[0], arr[n-1]);
    heapify(arr, 0, n-1);
}

void solve() {
    int n, k; cin >> n >> k;
    vi arr(n);
    for (auto &i: arr) cin >> i;
    looprev(i, n/2-1, 0) {
        heapify(arr, i, n);
    }
    loop(i, 1, k-1) {
        heapPop(arr, n-i+1);
    }
    cout << arr[0];
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
