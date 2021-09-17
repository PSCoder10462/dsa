#define ll long long
#include <queue>
long long minPenalty( vector<int> & arr){
	// Write your code here. 
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    for (int i: arr) minHeap.push(i);
    ll penalty = 0;
    while (minHeap.size() > 1) {
        ll sum = minHeap.top(); minHeap.pop();
        sum += minHeap.top(); minHeap.pop();
        minHeap.push(sum);
    	penalty += sum;
    }
    return penalty;
}
