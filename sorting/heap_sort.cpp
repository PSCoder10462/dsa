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

void heapify(vi &arr, int n, int ind) {
    int largest = ind;
    int left = 2*ind + 1,
        right = 2*ind + 2;
    if (left < n and arr[left] > arr[largest])
        largest = left;
    if (right < n and arr[right] > arr[largest])
        largest = right;
    if (largest == ind) return;
    swap(arr[ind], arr[largest]);
    heapify(arr, n, largest);
}

void heapsort(vi &arr, int n) {
    // build heap
    looprev(i, n/2-1, 0) heapify(arr, n, i);

    // heap sort
    looprev(i, n-1, 1) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void solve() {
    int n; cin >> n;
    vi v(n);
    for (auto &i: v) cin >> i;
    heapsort(v, n);
    for (auto const &i: v) cout << i << ' ';
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
