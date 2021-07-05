vector<int> sortBinaryArray(vector<int> arr, int n)  {
 	// Write your code here
    int j=0;
    
    for (int i=0; i<n; ++i) {
        if (not arr[i])
            std::swap(arr[j++], arr[i]);
    }
    
    return arr;
}
