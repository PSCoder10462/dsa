#include <queue>
int getFourthLargest(int arr[], int n)
{
    // Write your Code here
	priority_queue <int, vector<int>, greater<int>> minHeap;
    for (int i=0; i<n; ++i) {
        if (i < 4) {
            minHeap.push(arr[i]);
        } else {
            if (arr[i] > minHeap.top()) {
                minHeap.pop(); minHeap.push(arr[i]);
            }
        }
    }
    
    return (minHeap.size() == 4) ? minHeap.top() : -2147483648;
}
