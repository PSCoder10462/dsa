int switchingSubarray(vector<int> &arr, int n) {
    // Write your code here.
    
    if (n <= 2) return n;
    
    int j=0;
    
    int first = arr[j], second = arr[1];
    
    int len = 2;
    
    for (int i=2; i<n; ++i) {
        if ((i-j+1)%2) {
            if (arr[i]!=first) {
                first = second;
                second = arr[i];
                j = i-1;
            }
        } else {
            if (arr[i]!=second) {
                second = arr[i];
                j = i-1;
            }
        }
        
        len = std::max(len, i-j+1);
        
    }
    return len;
}
