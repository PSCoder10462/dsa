vector<int> findTriplets(vector<int> &arr, int n) 
{
    if (n < 3) return vector<int>{};
	
    vector<int> freqarr;
    
    for (int i=0; i<n; ++i) {
        if (arr[i]>=freqarr.size()) freqarr.resize(arr[i]+1, 0);
        freqarr[arr[i]]++;
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int ts = arr[i]+arr[j];
            if (ts < freqarr.size()) {
                if (freqarr[ts] > 0) {
                    return vector<int> {arr[i], arr[j], ts};
                }
            }
        }
    }
    
    return vector<int>{};
}
