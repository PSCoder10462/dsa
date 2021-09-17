#include <queue>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
	int median = 0;
    
    for (int i=0; i<n; ++i) {
        if (median > arr[i]) {
            // to be counted in lower half
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxHeap.push(arr[i]);
        } else {
            // to be counted in upper half
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } 
            minHeap.push(arr[i]);
        }
        
        // calculate median
		if (minHeap.size() == maxHeap.size())
            median = (minHeap.top() + maxHeap.top())/2;
        else if (minHeap.size() > maxHeap.size())
            median = minHeap.top();
        else 
            median = maxHeap.top();
        cout << median << ' ';
    }
}
