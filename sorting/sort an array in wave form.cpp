#include <algorithm>

vector<int> waveFormArray(vector<int> &arr, int n) {
    // Write your code here.
	std::sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i+=2) {
        std::swap(arr[i], arr[i+1]);
    }
    return arr;
}
