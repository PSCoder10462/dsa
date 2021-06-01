vector<int> findEquilibriumIndices(vector<int> &sequence) {
    // Write your code here.
    vector<int> ans;
    int n = sequence.size();
    if (n < 1) return ans;
    
    long long sum = 0;
    for (int i=0; i<n; ++i) sum += sequence[i];
    long long temp = 0;
    
    for (int i=0; i<n; ++i) {
        sum -= sequence[i];
        if (i>=1) temp += sequence[i-1];
        
        if (sum == temp)
            ans.push_back(i);
    }
    
    return ans;
    
}
