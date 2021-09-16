#define vi vector<int>
#include <queue>

vi getPrefixArray(vi &arr) {
    vi pre(arr.size()+1, 0);
	for (int i=1; i<=arr.size(); ++i) {
        pre[i] = pre[i-1] + arr[i-1];
    }   
    return pre;
}

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    vi pre = getPrefixArray(arr);
    
    // min heap
    priority_queue <int, vi, greater<int>> minHeap;
    
    //  Length of contiguous sub array
    for (int len = 1; len <= arr.size(); ++len) {
        //	Traverse the array
        for (int i=len; i <= arr.size(); ++i) {
            int cur_sum = pre[i]-pre[i-len];
            if (minHeap.size() < k) 
                minHeap.push(cur_sum);
			else {
                if (minHeap.top() < cur_sum) {
                    minHeap.pop(); minHeap.push(cur_sum);
                }
            }
        }
    }
    
    return minHeap.top();
}
