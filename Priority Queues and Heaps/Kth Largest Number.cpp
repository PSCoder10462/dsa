#include <queue>

class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       for (int i=0; i<k; ++i) {
           minHeap.push(arr[i]);
       }
       
       for (int i=k; i<arr.size(); ++i) {
           if (arr[i] > minHeap.top()) {
               minHeap.pop();
               minHeap.push(arr[i]);
           }
       }
    }

    void add(int num) {
        // Write your code here.
       if (num > minHeap.top()) {
           minHeap.pop();
           minHeap.push(num);
       }
    }

    int getKthLargest() {
       // Write your code here.
        return minHeap.top();
    }

};
