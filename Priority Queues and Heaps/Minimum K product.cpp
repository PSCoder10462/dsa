#include <queue>

int minProduct(vector<int> &arr, int n, int k) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i: arr) minHeap.push(i);
    long long prod = 1;
    while (k--) {
        prod *= minHeap.top();
        prod %= (long long)(1e9+7);
        minHeap.pop();
    }
    return prod;
}
