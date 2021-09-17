#include <queue>

vector<long long> multiplication(vector<int> & arr){
	// Write your code here. 
	priority_queue<int, vector<int>, greater<int>> Q;
    vector<long long> ans;
    int n = arr.size();
    
    long long int newProd = 1;
    
    for (int i=0; i<n; ++i) {
        if (i < 2) {
            Q.push(arr[i]);
            newProd *= arr[i];
	        ans.push_back(-1);
        } else if (i == 2) {
            Q.push(arr[i]);
            newProd *= arr[i];
	        ans.push_back(newProd);
        }
        else {
            if (arr[i] > Q.top()) {
                newProd /= Q.top(); Q.pop();
                newProd *= arr[i];
                Q.push(arr[i]);
            }
            ans.push_back(newProd);
        }
    }
    return ans;
}
